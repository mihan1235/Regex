#pragma once
#define DllExport   __declspec( dllexport )
#include <iostream>

DllExport void regex(std::istream& in, std::string mask, std::ostream& out);
