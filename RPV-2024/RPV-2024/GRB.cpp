#include "stdafx.h"

namespace GRB
{
		Greibach greibach(NS('S'), TS('$'),
			8,

			Rule(NS('S'), GRB_ERROR_SERIES + 0,						// Неверная структура программы	
				5,
				Rule::Chain(13, TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), NS('S')),
				Rule::Chain(12, TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}'), NS('S')),
				Rule::Chain(12, TS('t'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), NS('S')),
				Rule::Chain(11, TS('t'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}'), NS('S')),
				Rule::Chain(4, TS('m'), TS('{'), NS('N'), TS('}'))
			),
			
			Rule(NS('N'), GRB_ERROR_SERIES + 1,					// Ошибочный оператор
				20,
				/*идентификатор*/
				Rule::Chain(5, TS('d'), TS('t'), TS('i'), TS(';'), NS('N')),
				Rule::Chain(4, TS('d'), TS('t'), TS('i'), TS(';')),
				Rule::Chain(7, TS('d'), TS('t'), TS('i'), TS('='), NS('E'), TS(';'), NS('N')),
				Rule::Chain(6, TS('d'), TS('t'), TS('i'), TS('='), NS('E'), TS(';')),
				Rule::Chain(5, TS('i'), TS('='), NS('E'), TS(';'), NS('N')),
				Rule::Chain(4, TS('i'), TS('='), NS('E'), TS(';')),

				/*функция*/
				Rule::Chain(13, TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), NS('N')),
				Rule::Chain(12, TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}'), NS('N')),
				Rule::Chain(12, TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}')),
				Rule::Chain(11, TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}')),
				Rule::Chain(13, TS('t'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), NS('N')),
				Rule::Chain(12, TS('t'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}'), NS('N')),
				Rule::Chain(12, TS('t'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}')),
				Rule::Chain(11, TS('t'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}')),

				/*условный оператор*/
				Rule::Chain(8, TS('e'), TS('('), NS('L'), TS(')'), TS('{'), NS('N'), TS('}'), NS('N')),
				Rule::Chain(7, TS('e'), TS('('), NS('L'), TS(')'), TS('{'), NS('N'), TS('}')),

				/*цикл*/
				Rule::Chain(8, TS('c'), TS('('), NS('C'), TS(')'), TS('{'), NS('N'), TS('}'), NS('N')),
				Rule::Chain(7, TS('c'), TS('('), NS('C'), TS(')'), TS('{'), NS('N'), TS('}')),

				/*оператор вывода*/
				Rule::Chain(5, TS('p'), TS('('), NS('E'), TS(')'), TS(';')),
				Rule::Chain(6, TS('p'), TS('('), NS('E'), TS(')'), TS(';'), NS('N'))
				
			),

			Rule(NS('E'), GRB_ERROR_SERIES + 2,					// Ошибка в выражении 
				10,
				Rule::Chain(1, TS('i')),
				Rule::Chain(1, TS('l')),
				Rule::Chain(3, TS('('), NS('E'), TS(')')),
				Rule::Chain(3, TS('i'), TS('('), TS(')')),
				Rule::Chain(4, TS('i'), TS('('), NS('W'), TS(')')),
				Rule::Chain(2, TS('i'), NS('M')),
				Rule::Chain(2, TS('l'), NS('M')),
				Rule::Chain(4, TS('('), NS('E'), TS(')'), NS('M')),
				Rule::Chain(4, TS('i'), TS('('), TS(')'), NS('M')),
				Rule::Chain(5, TS('i'), TS('('), NS('W'), TS(')'), NS('M'))
			),

			Rule(NS('M'), GRB_ERROR_SERIES + 3,
				2,
				Rule::Chain(2, TS('v'), NS('E')),
				Rule::Chain(3, TS('v'), NS('E'), NS('M'))
			),

			Rule(NS('F'), GRB_ERROR_SERIES + 4, // ошибка в параметрах
				2,
				Rule::Chain(2, TS('t'), TS('i')),
				Rule::Chain(4, TS('t'), TS('i'), TS(','), NS('F'))
			),

			Rule(NS('W'), GRB_ERROR_SERIES + 5, // ошибка в параметрах вызываемой ф-ции
				4,
				Rule::Chain(1, TS('i')),
				Rule::Chain(1, TS('l')),
				Rule::Chain(3, TS('i'), TS(','), NS('W')),
				Rule::Chain(3, TS('l'), TS(','), NS('W'))
			),

			Rule(NS('L'), GRB_ERROR_SERIES + 6, // ошибка в услов операторе
				6,
				Rule::Chain(3, TS('i'), TS('v'), TS('i')),
				Rule::Chain(1, TS('l')),
				Rule::Chain(1, TS('i')),
				Rule::Chain(3, TS('i'), TS('v'), TS('l')),
				Rule::Chain(3, TS('l'), TS('v'), TS('i')),
				Rule::Chain(3, TS('l'), TS('v'), TS('l'))
			),

			Rule(NS('C'), GRB_ERROR_SERIES + 7, // ошибка в цикле
				2,
				Rule::Chain(10, TS('d'), TS('t'), TS('i'), TS(';'), NS('L'), TS(';'), TS('i'), TS('='), TS('i'), NS('M')),
				Rule::Chain(8, TS('i'), TS(';'), NS('L'), TS(';'), TS('i'), TS('='), TS('i'), NS('M'))
			)

		);

	Rule::Chain::Chain(short psize, GRBALPHABET s, ...)
	{
		this->nt = new GRBALPHABET[this->size = psize];

		int* ptr = (int*)&s;
		for (int i = 0; i < psize; i++)
			this->nt[i] = (short)ptr[i];
	}

	Rule::Rule(GRBALPHABET pnn, int iderroe, short psize, Chain c, ...)
	{
		this->nn = pnn;
		this->iderror = iderroe;
		this->chains = new Chain[this->size = psize];
		Chain* ptr = &c;
		for (int i = 0; i < psize; i++)
			this->chains[i] = ptr[i];
	}
	Greibach::Greibach(GRBALPHABET pstartN, GRBALPHABET pstbottomT, short psize, Rule r, ...)
	{
		this->startN = pstartN;
		this->stbottomT = pstbottomT;
		this->rules = new Rule[this->size = psize];
		Rule* ptr = &r;
		for (int i = 0; i < psize; i++)
			rules[i] = ptr[i];
	}

	Greibach getGreibach()
	{
		return greibach;
	}

	//возвращает номер следующего правила грамматики (или -1)
	short Greibach::getRule(GRBALPHABET pnn, Rule& prule)
	{
		short rc = -1, k = 0;
		while (k < this->size && rules[k].nn != pnn)
			k++;
		if (k < this->size)
			prule = rules[rc = k];
		return rc;
	}

	//возвращает правило с номером n
	Rule Greibach::getRule(short n)
	{
		Rule rc;
		if (n < this->size)
			rc = rules[n];
		return rc;
	}
	char* Rule::getCRule(char* b, short nchain)		//получить правило в виде N -> цепочка
	{
		char buf[200];
		b[0] = Chain::alphabet_to_char(this->nn);
		b[1] = '-';
		b[2] = '>';
		b[3] = 0x00;
		this->chains[nchain].getCChain(buf);
		strcat_s(b, sizeof(buf) + 5, buf);

		return b;
	}

	//подбор подходящего правила
	short Rule::getNextChain(GRBALPHABET t, Rule::Chain& pchain, short j)
	{
		short rc = -1;

		while (j < this->size && this->chains[j].nt[0] != t)
			j++;

		rc = (j < this->size ? j : -1);
		if (rc >= 0)
			pchain = chains[rc];
		return rc;
	}
	char* Rule::Chain::getCChain(char* b)		//получить правую сторону цепочки
	{
		for (int i = 0; i < this->size; i++)
			b[i] = Chain::alphabet_to_char(this->nt[i]);
		b[this->size] = 0;
		return b;
	}
}