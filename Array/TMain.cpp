/*
 * TMain
 */

#include "TMain.h"

#define ARRAY_SIZE 10

using namespace std;

#pragma warning(push)
#pragma warning(disable:4100)
int _tmain(int argc, _TCHAR **argv, _TCHAR **envp)
#pragma warning(pop)
{
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
    _setmode(_fileno(stderr), _O_WTEXT);

    ios::sync_with_stdio(false), tcin.tie(nullptr);

    int a[ARRAY_SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int *p = nullptr;
    p = a;

    /* 亂數排序陣列元素。 */
    array<int, ARRAY_SIZE> list;
    copy(begin(a), end(a), begin(list));
    random_device seed;
    shuffle(list.begin(), list.end(), default_random_engine(seed()));
    copy(begin(list), end(list), begin(a));

    tcout << _T("p[] = { ") << p[0] << _T(", ") << p[1] << _T(", ") << p[2] << _T(", ") << p[3] << _T(", ") << p[4] << _T(", ") << p[5] << _T(", ") << p[6] << _T(", ") << p[7] << _T(", ") << p[8] << _T(", ") << p[9] << _T(" };\n");
    tcout << _T("a[] = { ") << a[0] << _T(", ") << a[1] << _T(", ") << a[2] << _T(", ") << a[3] << _T(", ") << a[4] << _T(", ") << a[5] << _T(", ") << a[6] << _T(", ") << a[7] << _T(", ") << a[8] << _T(", ") << a[9] << _T(" };\n\n");

    streamsize len1 = 24, len2 = 2;
    tcout << setw(len1) << _T("sizeof(int) = ") << setw(len2) << sizeof(int) << _T('\n');
    tcout << setw(len1) << _T("sizeof(*p) = ") << setw(len2) << sizeof(*p) << _T('\n');
    tcout << setw(len1) << _T("sizeof(*a) = ") << setw(len2) << sizeof(*a) << _T("\n\n");

    tcout << setw(len1) << _T("sizeof(p[0]) = ") << setw(len2) << sizeof(p[0]) << " (" << p[0] << ") 0x" << &p[0] << _T('\n');
    tcout << setw(len1) << _T("sizeof(a[0]) = ") << setw(len2) << sizeof(a[0]) << " (" << a[0] << ") 0x" << &a[0] << _T("\n\n");

    for (int offset = 0; offset < sizeof(a) / sizeof(int); offset++)
    {
        tcout << _T("[offset = ") << offset << _T("]\n");
        tcout << setw(len1) << _T("sizeof(*(p + offset)) = ") << setw(len2) << sizeof(*(p + offset)) << _T(" (") << *(p + offset) << _T(") 0x") << p + offset << _T("\n");
        tcout << setw(len1) << _T("sizeof(a[offset]) = ") << setw(len2) << sizeof(a[offset]) << _T(" (") << a[offset] << _T(") 0x") << &a[offset] << _T("\n\n");
    }

    tcout << setw(len1) << _T("sizeof(long long) = ") << setw(len2) << sizeof(long long) << _T('\n');
    tcout << setw(len1) << _T("sizeof(p) = ") << setw(len2) << sizeof(p) << _T('\n');
    tcout << setw(len1) << _T("sizeof(a) = ") << setw(len2) << sizeof(a) << _T('\n');

    tcout << _T("請按任意鍵繼續 . . . ") << flush;
    _gettch();
}
