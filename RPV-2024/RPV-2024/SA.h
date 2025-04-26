#pragma once
#include "stdafx.h"

using namespace LA;

namespace SA
{
	struct Flags
	{
		bool flagDecFunction = false;   // ����������� ���������� �������
		bool flagCallFunction = false;  // ��������� ����� �������
		int indF = -1;					// ������ ������� � vector
		bool flagParametres = false;    // ���������� ���������� ������� // jVW6T
		bool flagInFunction = false;    // ����� � ���� �������
		bool flagReturn = false;        // ��������� return
		bool flagExpression = false;    // ���������� �� ���������
		IT::IDDATATYPE ExpressionType = IT::NODEF; // ��� ���������
		int ExpressionIndLT = -1;		// ������ ��������� � ������� ������
		bool flag�ondition = false;     // ��������� �������� ��������
		std::stack<std::pair<int, char>> braces_stack; //���� �������� ������ (������, ������)
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
