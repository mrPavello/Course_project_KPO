#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"

int convertFromOct(char* s, int line, int posword)
{
	int res = 0;
	for (int i = 1; i < strlen(s); ++i)
	{
		if (res >= INT_MAX || res <= INT_MIN)
		{
			throw Error::geterrorin(129, line, posword);
		}
		res *= 8;
		res += (s[i] - '0');
	}
	return res;
}

int convertFromBin(char* s, int line, int posword)
{
	int res = 0;
	for (int i = 1; i < strlen(s); ++i)
	{
		if (res >= INT_MAX || res <= INT_MIN)
		{
			throw Error::geterrorin(129, line, posword);
		}
		res *= 2;
		res += (s[i] - '0');
	}
	return res;
}

bool isNegative(char* s)
{

	if (s[0] == 'n')
	{
		return true;
	}

	return false;
}

bool LA::CheckInVector(std::vector<const char*> vector, const char* word)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (strcmp(word, vector[i]) == 0) return true;
	}
	return false;
}

string stackToString(stack<string> stk) {
	stack<string> tempStack;
	string result;
	while (!stk.empty()) {
		tempStack.push(stk.top());
		stk.pop();
	}

	while (!tempStack.empty()) {
		result += tempStack.top();
		tempStack.pop();
		result += "_";
	}
	return result;
}

void LA::InTables(LA::Tables& tables, int posword, int line, char* word, LA::Info& info)
{
	LA::Machines machines[N_GRAPHS] = {
			{LEX_NUMBER, FST::FST GRAPH_number},
			{LEX_STRING, FST::FST GRAPH_string},
			{LEX_CHAR, FST::FST GRAPH_char},
			{LEX_PRINT, FST::FST GRAPH_print},
			{LEX_FUNCTION, FST::FST GRAPH_function},
			{LEX_DEFINE, FST::FST GRAPH_define},
			{LEX_MAIN, FST::FST GRAPH_main},
			{LEX_RETURN, FST::FST GRAPH_return},
			{LEX_CYCLE, FST::FST GRAPH_cycle},
			{LEX_IF, FST::FST GRAPH_if},
			{LEX_COMMA, FST::FST GRAPH_COMMA},
			{LEX_SEMICOLON, FST::FST GRAPH_SEMICOLON},
			{LEX_LEFTHESIS, FST::FST GRAPH_LEFTHESIS},
			{LEX_RIGHTHESIS, FST::FST GRAPH_RIGHTHESIS},
			{LEX_LEFTBRACE, FST::FST GRAPH_LEFTBRCE},
			{LEX_RIGHTBRACE, FST::FST GRAPH_BRACELET},
			{LEX_LOWER, FST::FST GRAPH_LOWER},
			{LEX_BIGGER, FST::FST GRAPH_BIGGER},
			{LEX_LOWEROREQUAL, FST::FST GRAPH_LOWEROREQUAL},
			{LEX_BIGGEROREQUAL, FST::FST GRAPH_BIGGEROREQUAL},
			{LEX_NOTEQUAL, FST::FST GRAPH_NOTEQUAL},
			{LEX_DOUBLEEQUAL, FST::FST GRAPH_DOUBLEEQUAL},
			{LEX_PLUS, FST::FST GRAPH_PLUS},
			{LEX_MINUS, FST::FST GRAPH_MINUS},
			{LEX_EQUAL, FST::FST GRAPH_EQUAL},
			{LEX_LITERAL, FST::FST GRAPH_integer_literal},
			{LEX_LITERAL, FST::FST GRAPH_char_literal},
			{LEX_LITERAL, FST::FST GRAPH_integerx8_literal},
			{LEX_LITERAL, FST::FST GRAPH_integerx2_literal},
			{LEX_LITERAL, FST::FST GRAPH_string_literal},
			{LEX_ID, FST::FST GRAPH_id},
	};

	std::string LiteralPrefix = "L";
	char lexema = (char)"";
	int indexIT = -1;
	bool executeFlag = false;
	bool IdFlag = false;
	bool operatorFlag = false;

	union Value
	{
		int vint;							// значение integer
		struct
		{
			int len;						// количество символов в string
			char* str;						// cимволы string
		}vstr;								// значение string
		char* vchar;							// значение char
	}value;
	value.vint = 0;
	value.vstr.str = (char*)" ";
	value.vchar = (char*)' ';


	for (int i = 0; i < N_GRAPHS; i++)
	{
		if (FST::execute(machines[i].machine, word))
		{
			if (machines[i].lexema == 'i' || machines[i].lexema == 'l') // обработка литералов
			{
				if (i == N_GRAPHS - 6) // {LEX_LITERAL, FST::FST GRAPH_integer_literal}
				{
					info.iddatatype = IT::IDDATATYPE::NUM;
					info.idtype = IT::IDTYPE::L;
					if (isNegative(word))
					{
						value.vint = atoi(word + 1) * -1;
					}
					else
					{
						value.vint = atoi(word);
					}
					if (value.vint >= INT_MAX || value.vint <= INT_MIN)
					{
						throw Error::geterrorin(129, line, posword);
					}
				}
				else if (i == N_GRAPHS - 5) // {LEX_LITERAL, FST::FST GRAPH_char_literal}
				{
					info.iddatatype = IT::IDDATATYPE::CHAR;
					info.idtype = IT::IDTYPE::L;
					value.vchar = word;
				}
				else if (i == N_GRAPHS - 4)	// {LEX_LITERAL, FST::FST GRAPH_integerx8_literal}
				{
					info.iddatatype = IT::IDDATATYPE::NUM;
					info.idtype = IT::IDTYPE::L;
					if (isNegative(word))
					{
						value.vint = convertFromOct(word + 1, line, posword) * -1;
					}
					else
					{
						value.vint = convertFromOct(word, line, posword);
					}
				}
				else if (i == N_GRAPHS - 3)	// {LEX_LITERAL, FST::FST GRAPH_integerx2_literal}
				{
					info.iddatatype = IT::IDDATATYPE::NUM;
					info.idtype = IT::IDTYPE::L;
					if (isNegative(word))
					{
						value.vint = convertFromBin(word + 1, line, posword) * -1;
					}
					else
					{
						value.vint = convertFromBin(word, line, posword);
					}

				}
				else if (i == N_GRAPHS - 2) // {LEX_LITERAL, FST::FST GRAPH_string_literal}
				{
					info.iddatatype = IT::IDDATATYPE::STR;
					info.idtype = IT::IDTYPE::L;
					value.vstr = { (int)strlen(word), word };
					if (strlen(word) > TI_STR_MAXSIZE)
					{
						throw Error::geterrorin(126, line, posword);
					}
				}
				IdFlag = true;
			}
			else if (machines[i].lexema == 'v')
			{
				operatorFlag = true;
			}
			executeFlag = true;
			lexema = machines[i].lexema;
			break;
		}
	}

	if (executeFlag)
	{
		if (IdFlag)
		{
			indexIT = IT::IsId(tables.idTable, word);

			if (indexIT != TI_NULLIDX &&
				info.iddatatype != IT::IDDATATYPE::NODEF &&
				info.idtype != IT::IDTYPE::L &&
				info.idtype != IT::P)
			{
				throw Error::geterrorin(123, line, posword); // повторная инициализация
			}


			//если переменная с таким именем уже объявлена 
			//и текущая область видимости содержит область видимости идентификатора
			// значит переменная доступна в данной области
			// иначе, если текущая область видимости не содержит область видимости идентификатора,
			// то переменная в данной области недоступна и нужно выбросить ошибку
			//else if (indexIT != LT_TI_NULLIDX &&
			//		stackToString(info.defScopes).find(tables.idTable.table[indexIT].defScope) == string::npos)
			//{
			//	throw Error::geterrorin(122, line, posword); // использование без объявления
			//}
			else if (indexIT == TI_NULLIDX) // добавляем в таблицу индентификаторов
			{
				if (info.iddatatype == IT::IDDATATYPE::NODEF)
				{
					throw Error::geterrorin(122, line, posword); // использование без объявления
				}

				indexIT = tables.idTable.size;
				IT::Entry ITableEntry =
				{
					tables.LexTable.size,
					word,
					info.iddatatype,
					info.idtype,
					stackToString(info.defScopes)
				};

				memcpy(&ITableEntry.value, &value, sizeof(Value));
				IT::Add(tables.idTable, ITableEntry);

				info.iddatatype = IT::IDDATATYPE::NODEF;
				info.idtype = IT::IDTYPE::V;
			}
			else
			{
				info.iddatatype = IT::IDDATATYPE::NODEF;
				info.idtype = IT::IDTYPE::V;
			}

			LT::Entry LTableEntry =
			{
				lexema,
				line,
				tables.LexTable.size,
				indexIT,
				{'\0', '\0'},
				posword
			};

			LT::Add(tables.LexTable, LTableEntry);
		}
		else if (operatorFlag)
		{
			if (strlen(word) == 2)
			{
				LT::Entry LTableEntry =
				{
					lexema,
					line,
					tables.LexTable.size,
					indexIT,
					{word[0], word[1]},
					posword
				};
				LT::Add(tables.LexTable, LTableEntry);
			}
			else if (strlen(word) == 1)
			{
				LT::Entry LTableEntry =
				{
					lexema,
					line,
					tables.LexTable.size,
					indexIT,
					{word[0], '\0'},
					posword
				};
				LT::Add(tables.LexTable, LTableEntry);
			}
		}
		else
		{
			LT::Entry LTableEntry =
			{
				lexema,
				line,
				tables.LexTable.size,
				indexIT,
				{'\0', '\0'},
				posword
			};

			LT::Add(tables.LexTable, LTableEntry);
		}
	}
	else throw Error::geterrorin(113, line, posword);
}

void LA::GetInfo(LA::Info& info, char* word)
{
	if (strcmp(word, "number") == 0)
	{
		info.iddatatype = IT::IDDATATYPE::NUM;
	}
	else if (strcmp(word, "string") == 0)
	{
		info.iddatatype = IT::IDDATATYPE::STR;
	}
	else if (strcmp(word, "char") == 0)
	{
		info.iddatatype = IT::IDDATATYPE::CHAR;
	}
	else if (strcmp(word, "function") == 0)
	{
		info.idtype = IT::IDTYPE::F;
		info.flagFunc = true;
	}
	else if (strcmp(word, "main") == 0)
	{
		info.flagMain = true;
		info.defScopes.push("main");
	}
	else if (strcmp(word, "if") == 0)
	{
		info.flagIf = true;
		info.defScopes.push("if");
	}
	else if (strcmp(word, "cycle") == 0)
	{
		info.flagCycle = true;
		info.defScopes.push("cycle");
	}
	else if (strcmp(word, "(") == 0)
	{
		if (info.flagFunc)
		{
			info.flagParam = true;
			info.flagInFunc = true;
		}
	}
	else if (strcmp(word, ")") == 0)
	{
		if (info.flagFunc)
		{
			info.flagParam = false;
			info.flagInFunc = false;
		}
	}
	else if (info.idtype == IT::IDTYPE::F && !info.flagInMain)
	{
		for (int i = 0; i <= strlen(word); i++)
		{
			info.prefix[i] = word[i];
		}
		info.defScopes.push("global");
		info.functions.push_back((const char*)word);
	}
	else if (info.idtype == IT::IDTYPE::F)
	{
		for (int i = 0; i <= strlen(word); i++)
		{
			info.prefix[i] = word[i];
		}
		info.defScopes.push(string(word));
		info.functions.push_back((const char*)word);
	}
	else if (info.flagParam)
	{
		info.idtype = IT::IDTYPE::P;
	}
	else if (strcmp(word, "{") == 0)
	{
		if (info.flagMain)
		{
			info.flagInMain = true;
			info.flagMain = false;
		}
		else if (info.flagIf)
		{
			info.flagInIf = true;
			info.flagIf = false;
		}
		else if (info.flagCycle)
		{
			info.flagInCycle = true;
			info.flagCycle = false;
		}
		else if (info.flagFunc)
		{
			info.flagInFunc = true;
			info.flagFunc = false;
		}
	}
	else if (strcmp(word, "}") == 0)
	{
		if (info.flagInIf)
		{
			info.flagInIf = false;
		}
		else if (info.flagInCycle)
		{
			info.flagInCycle = false;
		}
		else if (info.flagInFunc)
		{
			info.flagInFunc = false;
		}
		else if (info.flagInMain)
		{
			info.flagInMain = false;
			info.prefix = NULL;
			info.prefix = new char(256);
		}
		info.defScopes.pop();
	}
}

LA::Tables LA::Lex_analyz(In::IN in) {
	LA::Tables tables;

	tables.LexTable = LT::Create();
	tables.idTable = IT::Create();

	LA::Info info;

	info.functions.push_back("lex_compare");
	info.functions.push_back("power");

	IT::Entry IdTableEntry =
	{
		-1,
		(char*)"lex_compare",
		IT::IDDATATYPE::NUM,
		IT::IDTYPE::F,
		"global"
	};
	IT::Add(tables.idTable, IdTableEntry);

	IdTableEntry =
	{
		-1,
		(char*)"power",
		IT::IDDATATYPE::NUM,
		IT::IDTYPE::F,
		"global",
	};
	IT::Add(tables.idTable, IdTableEntry);

	int i = 0;				// индекс по in.text
	int wordIndex = 0;
	int wordPosition = 0;		// позиция слова в строке
	int line = 1;			// текущая строка
	char* word = new char[256];


	while (i < in.size)
	{
		if (in.text[i] == '"')
		{
			while (true)
			{
				word[wordIndex++] = in.text[i++];
				wordPosition++;
				if (in.text[i] == '\n')
				{
					line++;
					wordPosition = 0;
				}
				if (in.text[i] == '"' || in.text[i] == '\0') break;
			}
			word[wordIndex++] = in.text[i++];
			word[wordIndex] = '\0';

			GetInfo(info, word);
			InTables(tables, wordPosition, line, word, info);

			word = NULL;
			word = new char[256];
			wordIndex = 0;
		}
		else if (in.code[in.text[i]] == in.T)
		{
			while (in.code[in.text[i]] == in.T)
			{
				word[wordIndex++] = in.text[i++];
				wordPosition++;
			}

			word[wordIndex] = '\0';
			wordIndex = 0;

			GetInfo(info, word);
			InTables(tables, wordPosition, line, word, info);

			word = NULL;
			word = new char[256];
		}
		else if (in.code[in.text[i]] == in.S)
		{
			word[wordIndex++] = in.text[i++];
			word[wordIndex] = '\0';

			GetInfo(info, word);
			InTables(tables, wordPosition, line, word, info);

			wordPosition++;
			wordIndex = 0;
			word = NULL;
			word = new char[256];
		}
		else if (in.code[in.text[i]] == in.O)
		{
			while (in.code[in.text[i]] == in.O)
			{
				word[wordIndex++] = in.text[i++];
				wordPosition++;
			}

			word[wordIndex] = '\0';
			wordIndex = 0;

			GetInfo(info, word);
			InTables(tables, wordPosition, line, word, info);

			word = NULL;
			word = new char[256];
		}
		else if (in.code[in.text[i]] == in.P)
		{
			if (in.text[i] == IN_CODE_ENDL)
			{
				line++;
				wordPosition = 0;
			}
			wordIndex = 0;
			i++;
		}
	}
	return tables;
}