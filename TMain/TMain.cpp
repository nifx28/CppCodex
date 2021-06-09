/*
 * TMain
 */

#include "TMain.h"

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

    for (int i = 0; i < argc; i++)
    {
        tcout << _T("命令列參數 argv[") << i << _T("] = \"") << argv[i] << "\"\n";
    }

    _TCHAR* szComSpec = nullptr;
    size_t requiredSize = 0;
    _tgetenv_s(&requiredSize, nullptr, 0, _T("ComSpec"));

    if (!requiredSize)
    {
        tcerr << _T("查無環境變數 ComSpec！") << '\n';
        exit(1);
    }
    else
    {
        szComSpec = new _TCHAR[requiredSize];

        if (!szComSpec)
        {
            tcerr << _T("無法配置記憶體！") << '\n';
            exit(1);
        }

        _tgetenv_s(&requiredSize, szComSpec, requiredSize, _T("ComSpec"));
    }

    tcout << _T("\n環境變數 ComSpec = \"") << szComSpec << "\"\n";

    if (szComSpec != nullptr)
    {
        delete szComSpec;
        szComSpec = nullptr;
    }

    tcout << _T("請按任意鍵繼續 . . . ") << flush;
    _gettch();
}
