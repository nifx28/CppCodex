/*
 * 金字塔建築師：工具包。
 */

// 第一優先：先行編譯標頭檔。
#include "Precompiled.h"
#include "PyramidToolset.h"

// 引用命名空間，禁止在標頭檔內使用。
using namespace std;

/*
 * 切換 命令提示字元 寬字元顯示。
 */
void setmode(int mode)
{
    _setmode(_fileno(stdin), mode);
    _setmode(_fileno(stdout), mode);
    _setmode(_fileno(stderr), mode);
}

/*
 * 印出金字塔。
 */
void print(size_t num, size_t offset)
{
    wcout << wstring(offset, L' ') << wstring(num, L'*') << ENDL;
}
