/*
 * 金字塔建築師。
 */

#include "Pyramid.h"

using namespace std;

using num = array<wchar_t, 4>;

#pragma warning(push)
#pragma warning(disable:4100)
int wmain(int argc, wchar_t **argv)
#pragma warning(pop)
{
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
    _setmode(_fileno(stderr), _O_WTEXT);

    wcout << L"請輸入金字塔高度：";

    num pyH;
    wcin.getline(&pyH[0], 4);

    int num = 0;
    wstringstream ss;
    ss << &pyH[0];
    ss >> num;

    wcout << L"已輸入：" << num << L'\n';

    int numMax = num * 2;

    for (int i = 1; i < numMax; i++)
    {
        print(static_cast<size_t>(i + 1 > num ? num - (i - num) : i));
    }
}

void print(size_t num)
{
    wcout << wstring(num, L'*') << L'\n';
}
