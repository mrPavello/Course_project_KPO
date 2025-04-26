#include "stdafx.h"

namespace Parm {
	//функция обрабатывает параметры командной строки
	PARM getparm(int argc, wchar_t* argv[]) {
		PARM p = { L"", L"", L"" };
		bool isInputProvided = false;
		for (int i = 1; i < argc; ++i) {//проверка параметров, пропуская первый - названиие програмы
			if (wcsstr(argv[i], PARM_IN)) {//если встретился ключ PARM_IN
				if (wcslen(argv[i] + wcslen(PARM_IN)) > PARM_MAX_SIZE) {//проверка длины входного параметра
					throw ERROR_THROW(104);
				}
				wcscpy_s(p.in, argv[i] + wcslen(PARM_IN));//запись имени файла в массив, пропуская ключ параметра
				isInputProvided = true;//параметр найден
			}
			else if (wcsstr(argv[i], PARM_OUT)) {
				if (wcslen(argv[i] + wcslen(PARM_OUT)) > PARM_MAX_SIZE) {
					throw ERROR_THROW(104);
				}
				wcscpy_s(p.out, argv[i] + wcslen(PARM_OUT));
			}
			else if (wcsstr(argv[i], PARM_LOG)) {
				if (wcslen(argv[i] + wcslen(PARM_LOG)) > PARM_MAX_SIZE) {
					throw ERROR_THROW(104);
				}
				wcscpy_s(p.log, argv[i] + wcslen(PARM_LOG));
			}
		}
		if (!isInputProvided) {//если параметр не найден
			throw ERROR_THROW(100);
		}

		if (p.out[0] == '\0') {//если после ключа нет имени файла, установка имени файла по умолчанию
			wcscpy_s(p.out, PARM_MAX_SIZE, p.in);
			wcsncat_s(p.out, PARM_OUT_DEFAULT_EXT, wcslen(PARM_OUT_DEFAULT_EXT));
		}
		if (p.log[0] == '\0') {
			wcscpy_s(p.log, PARM_MAX_SIZE, p.in);
			wcsncat_s(p.log, PARM_LOG_DEFAULT_EXT, wcslen(PARM_LOG_DEFAULT_EXT));
		}
		return p;
	}

}
