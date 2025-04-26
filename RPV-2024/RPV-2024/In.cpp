#include "stdafx.h" 
#include <unordered_set>

namespace In {
	IN getin(wchar_t infile[]) {
		IN in_result;
		unsigned char symbol;
		in_result.size = 0;
		in_result.ignor = 0;
		in_result.lines = 0;
		std::ifstream file;

		file.open(infile);
		if (!file.is_open()) {
			throw ERROR_THROW(110);
		}
		in_result.text = new unsigned char[IN_MAX_LEN_TEXT];
		char* tmp = new char[IN_MAX_LEN_TEXT];
		static const unordered_set<char> operators = {
			'{', '}', '(', ')', ';', ',', '+', '-', '=', '>', '<', '!',
		};

		while (file.getline(tmp, 100)) {
			bool lineStart = true;
			bool prevWasSpace = false;
			bool nextIsOperator = false;
			bool prevWasOperator = false;
			bool inQuotes = false;
			unsigned short int countQuotes = 0;

			for (int position = 0; position < strlen(tmp); position++) {
				if (tmp[position] == '"') {
					if (countQuotes <= 2) {
						inQuotes = true;
						countQuotes++;
					}
					else {
						inQuotes = false;
						countQuotes = 0;
					}
				}

				if (lineStart && (tmp[position] == ' ' || tmp[position] == '\t')) {
					in_result.ignor++;
					continue;
				}
				lineStart = false;

				if (position > 0 && tmp[position - 1] == ' ') {
					prevWasSpace = true;
				}
				else {
					prevWasSpace = false;
				}

				if ((tmp[position] == ' ' || tmp[position] == '\t') && prevWasSpace && !inQuotes) {
					in_result.ignor++;
					continue;
				}

				if (tmp[position] == '\t' && !prevWasSpace) {
					prevWasSpace = true;
					tmp[position] = ' ';
				}

				if (operators.find(tmp[position - 1]) != operators.end() && !inQuotes) {
					prevWasOperator = true;
				}
				else {
					prevWasOperator = false;
				}

				if (operators.find(tmp[position + 1]) != operators.end() && !inQuotes) {
					nextIsOperator = true;
				}
				else {
					nextIsOperator = false;
				}

				if (tmp[position] == ' ' && prevWasOperator) {
					in_result.ignor++;
					continue;
				}

				if (tmp[position] == ' ' && nextIsOperator) {
					in_result.ignor++;
					continue;
				}



				switch (in_result.code[int((unsigned char)tmp[position])])
				{
				case IN::S:
				case IN::P:
				case IN::Q:
				case IN::O:
				case IN::T:
					in_result.text[in_result.size++] = (unsigned)tmp[position];
					break;

				case IN::F:
					in_result.text[in_result.size] = '\0';
					throw ERROR_THROW_IN(111, in_result.lines, position + 1, in_result.text);
					break;

				case IN::I:
					in_result.ignor++;
					break;

				default:
					throw ERROR_THROW_IN(111, in_result.lines, position + 1, in_result.text);
				}
			}
			in_result.lines++;
			in_result.text[in_result.size++] = '|';
		}
		in_result.text[in_result.size] = '\0';
		return in_result;
	}
}