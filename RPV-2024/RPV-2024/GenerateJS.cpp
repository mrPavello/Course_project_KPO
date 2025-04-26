#include "stdafx.h"
#include "GenerateJS.h"

namespace GJS {
    void GenerateJS(LT::LexTable& lexTable, IT::IdTable& idTable, string& outputFilePath) {
        std::ofstream outputFile(outputFilePath);
        if (!outputFile.is_open()) {
            throw ERROR_THROW(112); 
        }

        outputFile << "import { lex_compare, power } from './standartLib.js';\n\n\n";
        string code = GetCode(lexTable, idTable);
        outputFile << code;

        outputFile.close();
    }

    string GetCode(LT::LexTable& lexTable, IT::IdTable& idTable) {
        string code = "";
        bool inParentheses = false;
        bool inMain = false;
        int tabLevel = 0;
        const string tab = "\t"; 

        for (int i = 0; i < lexTable.size; ++i) {
            LT::Entry lex = lexTable.table[i];

            // ƒобавл€ем отступы перед новой строкой
            if (!code.empty() && code.back() == '\n') {
                if (lex.lexema == '}') {
                    for (int i = 0; i < tabLevel - 1; i++) {
                        code += tab;
                    }
                }
                else {
                    for (int i = 0; i < tabLevel; i++) {
                        code += tab;
                    }
                }
            }

            switch (lex.lexema) {
            case 't': 
                i++;
                if (lexTable.table[i].lexema == 'f') {
                    code += "function ";
                }
                else {
                    i--;
                }
                break;

            case 'd': 
                i++;
                if (lexTable.table[i].lexema == 't') {
                    code += "let ";
                }
                break;

            case 'm':
                code += "(function ()";
                inMain = true;
                break;

            case 'e': 
                code += "if ";
                break;

            case 'c': 
                code += "for ";
                break;

            case 'i': 
                if (lex.indID != TI_NULLIDX) {
                    code += string(idTable.table[lex.indID].id);
                }
                break;

            case 'p':
                code += "console.log";
                break;

            case 'r':
                code += "return ";
                break;

            case '=':
                code += " = ";
                break;

            case 'v':
                if (lex.operatorValue[0] != '\0') {
                    size_t length = (lex.operatorValue[1] == '\0') ? 1 : 2;
                    code += " " + string(lex.operatorValue, length) + " ";
                }
                break;

            case 'l':
                if (lex.indID != TI_NULLIDX) {
                    IT::Entry entry = idTable.table[lex.indID];
                    if (entry.iddatatype == IT::NUM) {
                        code += to_string(entry.value.vint);
                    }
                    else if (entry.iddatatype == IT::CHAR) {
                        code += string(idTable.table[lex.indID].value.vchar);
                    }
                    else if (entry.iddatatype == IT::STR) {
                        code += string(idTable.table[lex.indID].value.vstr.str);
                    }
                }
                break;

            case '(':
                code += "(";
                inParentheses = true;
                break;

            case ')':
                code += ")";
                inParentheses = false;
                break;

            case '{':
                code += " {\n";
                tabLevel++;
                break;

            case '}':
                tabLevel--;
                if (tabLevel == 0 && inMain) {
                    code += "})();\n"; 
                    inMain = false;
                }
                else {
                    code += "}\n\n";
                }
                break;

            case ';':
                code += inParentheses ? "; " : ";\n";
                break;

            case ',': 
                code += ", ";
                break;

            default:
                break;
            }
        }

        return code;
    }
}