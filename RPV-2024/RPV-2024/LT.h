#pragma once
#include "string"
#define LEXEMA_FIXSIZE	1
#define LT_MAXSIZE		4096
#define LT_TI_NULLIDX	0xffffffff
#define LEX_NUMBER		't'
#define LEX_STRING		't'
#define LEX_CHAR		't'
#define LEX_ID			'i'
#define LEX_LITERAL		'l'
#define LEX_FUNCTION	'f'
#define LEX_DEFINE		'd'
#define LEX_RETURN		'r'
#define LEX_PRINT		'p'
#define LEX_CYCLE		'c'
#define LEX_IF			'e'
#define LEX_SEMICOLON	';'
#define LEX_COMMA		','
#define LEX_LEFTBRACE	'{'
#define LEX_RIGHTBRACE	'}'
#define LEX_LEFTHESIS	'('
#define LEX_RIGHTHESIS	')'
#define LEX_BIGGER		'v'
#define LEX_LOWER		'v'
#define LEX_DOUBLEEQUAL 'v'
#define LEX_NOTEQUAL	'v'
#define LEX_BIGGEROREQUAL	'v'
#define LEX_LOWEROREQUAL	'v'
#define LEX_PLUS		'v'
#define LEX_MINUS		'v'
#define LEX_EQUAL       '='
#define LEX_MAIN		'm'

namespace LT
{

	struct Entry
	{
		char lexema; // лексема
		int sn;						// номер строки
		int idxLT;					// индекс в таблице лексем
		int indID;					// индес в таблицце индентификаторов
		char operatorValue[2];			// значение оператора дл€ операторов.
		int wordPosition;				// позици€ в строке
	};

	struct LexTable
	{
		int maxsize;				 // макс размер таблицы лексем
		int size;					 // текущий размер
		Entry* table; 				 // массив строк таблицы лексем
	};


	LexTable Create();

	void Add(
		LexTable& lextable,			 // экземпл€р табл лексем
		Entry entry					 // строка таблицы лексем
	);

	Entry GetEntry(					 // получить строку в таблицу лексем
		LexTable& lextable,			 // экземпл€р табл лексем
		int n						 // номер получаемой строки			
	);

	void Delete(LexTable& lextable); // удалить таблицу лексем

	void PrintTable(LexTable& lextable, const std::string& filePath);
};