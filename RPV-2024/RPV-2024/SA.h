#pragma once
#include "stdafx.h"

using namespace LA;

namespace SA
{
	struct Flags
	{
		bool flagDecFunction = false;   // обнаруженно объявление функции
		bool flagCallFunction = false;  // обнаружен вызов функции
		int indF = -1;					// индекс функции в vector
		bool flagParametres = false;    // считывание параметров функции // jVW6T
		bool flagInFunction = false;    // вошли в блок функции
		bool flagReturn = false;        // встретили return
		bool flagExpression = false;    // наткнулись на выражение
		IT::IDDATATYPE ExpressionType = IT::NODEF; // тип выражения
		int ExpressionIndLT = -1;		// индекс выражения в таблице лексем
		bool flagСondition = false;     // обнаружен условный оператор
		std::stack<std::pair<int, char>> braces_stack; //стек фигурных скобок (индекс, скобка)
	};

	struct Function
	{
		IT::Entry function;
		std::vector<IT::IDDATATYPE> parameters;
	};



	std::vector<SA::Function> SemAnalysis(LA::Tables tables);

	void GetFlags(char lexema, SA::Flags& flags, int current_index);

	int CheckInFunctions(std::vector<SA::Function> functions, char* id);
}
