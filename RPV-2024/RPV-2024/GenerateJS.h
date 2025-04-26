#pragma once
#include "stdafx.h"
#include "LT.h"
#include "IT.h"
#include <fstream>

namespace GJS {
    void GenerateJS(LT::LexTable& lexTable, IT::IdTable& idTable, string& outputFilePath);
    string GetCode(LT::LexTable& lexTable, IT::IdTable& idTable);
}
