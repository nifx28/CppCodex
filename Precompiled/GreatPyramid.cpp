/*
 * 金字塔建築師。
 */

// 第一優先：先行編譯標頭檔。
#include "Precompiled.h"
#include "PyramidToolset.h"

// 引用命名空間，禁止在標頭檔內使用。
using namespace std;

// 定義宣告別名。
using num = array<wchar_t, 4>;

// 開頭：忽略未使用的函式參數。
#pragma warning(push)
#pragma warning(disable:4100)
int wmain(int argc, wchar_t **argv)
// 結束：忽略未使用的函式參數。
#pragma warning(pop)
{
    setmode(_O_WTEXT);

    vector<num> lines;
    wcout << L"請輸入金字塔高度：";

    for (num pyH; wcin.getline(&pyH[0], 4); ) // 最多輸入 3 個數字，加上 1 個換行。
    {
        lines.push_back(pyH);
    }

    for (num& pyH : lines)
    {
        int num = 0;
        wstringstream ss;
        ss << &pyH[0];
        ss >> num;

        wcout << L"已輸入：" << num << ENDL;

        int numMax = num * 2;

        for (int i = 1; i < numMax; i++)
        {
            print(static_cast<size_t>(i + 1 > num ? num - (i - num) : i));
        }
    }
}
