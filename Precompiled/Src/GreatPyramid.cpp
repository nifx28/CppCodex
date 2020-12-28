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

    while (!wcin.eof())
    {
        num pyH;
        wcin.getline(&pyH[0], 4); // 最多輸入 3 個數字，加上 1 個換行。

        if (!wcin.fail())
        {
            if (*(&pyH[0]) != L'#') // # 開頭為註解。
            {
                lines.push_back(pyH);
            }
        }
        else // 超過三個字報錯。
        {
            wcin.clear(); // 清除 failbit。
            wcin.ignore(numeric_limits<streamsize>::max(), ENDL); // 超過三個字無法擷取，忽略。
        }
    }

    wcout << wstring(2, ENDL);

    for (num& pyH : lines)
    {
        int num = 0;
        wstringstream ss;
        ss << &pyH[0];
        ss >> num;

        wcout << L"已輸入：" << num << ENDL << ENDL;

        int numWidth = num + 6, numDouble = num * 2, numHalf = num / 2;
        int tree = 5, offset = 6;

        for (int i = 1; i < numWidth; i++)
        {
            if (i < num)
            {
                print(static_cast<size_t>(i * 2 - 1), static_cast<size_t>(offset + numHalf - (i - numHalf)));
            }
            else
            {
                if (i + 2 >= numWidth)
                {
                    tree += 2;
                }

                print(static_cast<size_t>(tree), static_cast<size_t>(offset + (numDouble - tree) / 2 - 1));
            }
        }

        wcout << ENDL;
    }
}
