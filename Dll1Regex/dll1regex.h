#pragma once
#include <iostream>

#ifdef __linux__ 
    void regex(std::istream& in, std::string mask, std::ostream& out);
#endif 

#ifdef _WIN32
    #define DllExport   __declspec( dllexport )
    DllExport void regex(std::istream& in, std::string mask, std::ostream& out);
#endif
