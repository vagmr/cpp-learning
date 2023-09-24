#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int t = 1;
    while (t++)
    {
        COORD huoquan;
        COORD core = {40, 15};
        int R = 13;
        huoquan.X = core.X + 2 * R * cos(t * 0.2);
        huoquan.Y = core.Y + R * sin(t * 0.2);
        system("cls");
        SetConsoleCursorPosition(hConsole, core);
        printf("圆心");
        SetConsoleCursorPosition(hConsole, huoquan);
        printf("火圈");
        CONSOLE_CURSOR_INFO info = {1, false};
        SetConsoleCursorInfo(hConsole, &info);
    }
}