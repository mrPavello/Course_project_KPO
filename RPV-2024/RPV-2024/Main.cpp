#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "Rus");
    Log::LOG log = Log::INITLOG;
    Out::OUT out = Out::INITOUT;
    string ti_file_path = "Identificators.txt";
    string tl_file_path = "Lexems.txt";
    string js_code_file = "../RPV_app/program.js";
    try
    {
        Parm::PARM parm = Parm::getparm(argc, argv);
        
        log = Log::getlog(parm.log);
        out = Out::getout(parm.out);

        Log::WriteLog(log);
        Log::WriteParm(log, parm);
        In::IN in = In::getin(parm.in);

        Log:WriteIn(log, in);
        Out::WriteOut(out, in);

        LA::Tables Tables = LA::Lex_analyz(in);

        
        LT::PrintTable(Tables.LexTable, tl_file_path);
        IT::PrintTable(Tables.idTable, ti_file_path);
        MFST_TRACE_START                                    // отладка
        MFST::Mfst mfst(Tables, GRB::getGreibach());    // автомат
        mfst.start();                                       // старт синтаксического анализа
        mfst.savededucation();                              //  сохранить вывести правило вывода
        mfst.printrules();                                  // вывывести правило вывода
    

        std::vector<SA::Function> functions = SA::SemAnalysis(Tables);
        GJS::GenerateJS(Tables.LexTable, Tables.idTable, js_code_file);

        Log::Close(log);
        Out::Close(out);
    }
    catch (Error::ERROR e)
    {
        Log::WriteError(log, e);
        Out::WriteError(out, e);
        cout << "Ошибка " << e.id << ": " << e.message << ", строка " << e.inext.line << ", позиция " << e.inext.col << std::endl;
    }
    system("pause");
    return 0;
} 
