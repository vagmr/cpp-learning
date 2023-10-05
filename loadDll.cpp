#include <cstdio>
#include <windows.h>
int main()
{
    HMODULE hmodule = LoadLibrary(L"./vMath_d.dll");
    if (!hmodule)
    {
        printf("dll打开失败: %d\n", GetLastError());
    }
    else
    {
        FARPROC funcPtr = GetProcAddress(hmodule, "getVersion");
        void (*vgVersion)() = reinterpret_cast<void (*)()>(funcPtr);
        printf("%s \n", vgVersion);
    }

    if (hmodule)
    {
        FreeLibrary(hmodule);
    }
    getchar();
    return 0;
}