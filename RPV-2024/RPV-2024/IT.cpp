#include "stdafx.h"

using namespace IT;

IdTable IT::Create()
{
	IdTable IdTable = {};
	IdTable.maxsize = TI_MAXSIZE;
	IdTable.size = 0;
	IdTable.table = new Entry[IdTable.maxsize];
	if (IdTable.size > TI_MAXSIZE) throw ERROR_THROW(117);
	return IdTable;
}

void IT::Add(IdTable& idtable, Entry entry)
{
	idtable.table[idtable.size] = entry;
	idtable.size++;
}

void IT::Delete(IdTable& idtable)
{
	IdTable temp = {};
	idtable = temp;
}

Entry IT::GetEntry(IdTable& idtable, int n)
{
	return idtable.table[n];
	if (n > idtable.size) throw ERROR_THROW(119);
}

int IT::IsId(IdTable& idtable, char* id)
{
	for (int i = idtable.size - 1; i >= 0; i--)
	{
		if (strcmp(id, idtable.table[i].id) == 0)
		{
			return i;
		}
	}
	return TI_NULLIDX;
}
void IT::PrintTable(IdTable& idtable, const std::string& filePath) 
{
	ofstream fout(filePath);
	if (!fout.is_open()) {
		throw ERROR_THROW(114);
	}
	Entry e;
	fout << "\t\t\t\tТаблица идентификаторов";
	fout << endl;
	fout << "Тип\t\t\t|" << "Имя" << "\t\t\t\t\t" << "Тип данных" << "\t\t" << "Впервые в тл" << "\t\t" << "Значение" << endl;
	for (int i = 0; i < idtable.size; i++)
	{
		e = idtable.table[i];
		switch (e.idtype)
		{

		case IT::L:
			switch (e.iddatatype)
			{
			case IT::NUM:
				fout << "Литерал\t\t\t|" << e.id << "\t\t\t\t|" << "NUM" << "\t\t\t|" << e.idxfirstLE << "\t\t\t|" << e.value.vint << endl;
				break;
			case IT::STR:
				fout << "Литерал\t\t\t|" << e.id << "\t\t\t\t|" << "STR" << "\t\t\t|" << e.idxfirstLE << "\t\t\t|" << e.value.vstr.str << endl;
				break;
			case IT::CHAR:
				fout << "Литерал\t\t\t|" << e.id << "\t\t\t\t|" << "CHAR" << "\t\t\t|" << e.idxfirstLE << "\t\t\t|" << e.value.vchar << endl;
				break;
			}
			break;
		case IT::V:
			switch (e.iddatatype)
			{
			case IT::NUM:
				fout << "Переменная\t\t|" << e.id << "\t\t\t|" << "NUM" << "\t\t\t|" << e.idxfirstLE << endl;
				break;
			case IT::STR:
				fout << "Переменная\t\t|" << e.id << "\t\t\t|" << "STR" << "\t\t\t|" << e.idxfirstLE << endl;
				break;
			case IT::CHAR:
				fout << "Переменная\t\t|" << e.id << "\t\t\t|" << "CHAR" << "\t\t\t|" << e.idxfirstLE << endl;
				break;
			}
			break;
		case IT::F:
			switch (e.iddatatype)
			{
			case IT::NUM:
				fout << "Функция\t\t\t|" << e.id << "\t\t\t|" << "NUM" << "\t\t\t|" << e.idxfirstLE << endl;
				break;
			case IT::STR:
				fout << "Функция\t\t\t|" << e.id << "\t\t\t|" << "STR" << "\t\t\t|" << e.idxfirstLE  << endl;
				break;
			case IT::CHAR:
				fout << "Функция\t\t\t|" << e.id << "\t\t\t|" << "CHAR" << "\t\t\t|" << e.idxfirstLE << endl;
				break;
			}
			break;
		case IT::P:
			switch (e.iddatatype)
			{
			case IT::NUM:
				fout << "Параметр\t\t|" << e.id << "\t\t\t|" << "NUM" << "\t\t\t|" << e.idxfirstLE  << endl;
				break;
			case IT::STR:
				fout << "Параметр\t\t|" << e.id << "\t\t\t|" << "STR" << "\t\t\t|" << e.idxfirstLE << endl;
				break;
			case IT::CHAR:
				fout << "Параметр\t\t|" << e.id << "\t\t\t|" << "CHAR" << "\t\t\t|" << e.idxfirstLE << endl;
				break;
			}
			break;
		}

	}
	fout.close();
}


