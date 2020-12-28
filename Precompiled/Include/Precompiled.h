// 只引入一次標頭檔的新標示方式。
#pragma once

// 由於刻意使用 /Wall /WX 參數把錯誤訊息全開，並把警告視為錯誤。
// 開頭：只要是標準函式庫裡面的錯誤，一律忽略。
#pragma warning(push)
#pragma warning(disable:4668 4710 4711 5039)

// C++ 標準函式庫。
#include <iostream>
#include <vector>
#include <array>
#include <sstream>

// C++ 版本的 C 標準函式庫引用方式，不需要 .h 標頭檔。
#include <cstdlib>

// Windows Kits 函式庫。
// "C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\ucrt\"
#include <fcntl.h>
#include <io.h>

// 只引用必要的 <Windows.h> 內建標頭。
// "C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\um\"
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>

// 結束：只要是標準函式庫裡面的錯誤，一律忽略。
#pragma warning(pop)

// 不使用 std::endl 增加效能。
#define ENDL L'\n'
