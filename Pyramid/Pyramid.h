#pragma once

#pragma warning(push)
#pragma warning(disable:4668 4710 4711 5039)

#include <iostream>
#include <array>
#include <sstream>

#include <fcntl.h>
#include <io.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#pragma warning(pop)

void print(size_t num);
