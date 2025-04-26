#pragma once
#define ID_MAXSIZE		5
#define TI_MAXSIZE		4096
#define TI_INT_DEFAULT	0x00000000
#define TI_STR_DEFAULT	0x00
#define TI_NULLIDX		0xffffffff
#define TI_STR_MAXSIZE	255
#define IDENTICATOR_MAXSIZE 20
 
namespace IT {

	enum IDDATATYPE { NUM = 1, STR = 2, CHAR = 3, INT8 = 4, NODEF = 0 };		// ���� ������ ����������������: integer, string, char
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4 };    // ���� ���������������: ����������, �������, ��������, �������

	struct Entry {
		int idxfirstLE;							// ������ ������ ������ � ������� ������
		char* id;								// �������������
		IDDATATYPE iddatatype;					// ��� ������
		IDTYPE idtype;							// ��� ��������������
		string defScope;
		union Value
		{
			int vint;							// �������� integer
			struct
			{
				int len;						// ���������� �������� � string
				char* str;						// c������ string
			}vstr;								// �������� string
			char* vchar;							// �������� char
		}value;

	};

	struct IdTable
	{
		int maxsize;
		int size;
		Entry* table;
	};

	IdTable Create();

	void Add(IdTable& idtable, Entry entry);

	Entry GetEntry(IdTable& idtable, int n);

	int IsId(IdTable& idtable, char* id);		// ���� �� �������������� � �������

	void Delete(IdTable& idtable);
	void PrintTable(IdTable& idtable, const std::string& filePath);
}