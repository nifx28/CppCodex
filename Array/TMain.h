#pragma once

#pragma warning(push)
#pragma warning(disable:4710 4711)

#include <iostream>
#include <iomanip>
#include <sstream>
#include <array>
#include <random>

#ifdef _UNICODE
#define tcin std::wcin
#define tcout std::wcout
#define tcerr std::wcerr
#define tostream std::wostream
#define tostringstream std::wostringstream
#else
#define tcin std::cin
#define tcout std::cout
#define tcerr std::cerr
#define tostream std::ostream
#define tostringstream std::ostringstream
#endif

#include <tchar.h>
#include <fcntl.h>
#include <io.h>
#include <conio.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#pragma warning(pop)
