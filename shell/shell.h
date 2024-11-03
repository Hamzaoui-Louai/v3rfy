#ifndef SHELL
#define SHELL

#include <Windows.h>
#include <iostream>

namespace Shell
{
    class shell{
    private:
        void clearScreen() 
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(hConsole, &csbi);
            COORD coord = { 0, 0 };
            DWORD count;
            DWORD cellCount = static_cast<DWORD>((csbi.srWindow.Right - csbi.srWindow.Left + 1) * (csbi.srWindow.Bottom - csbi.srWindow.Top + 1));
            FillConsoleOutputCharacter(hConsole, ' ', cellCount, coord, &count);
            FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, coord, &count);
            SetConsoleCursorPosition(hConsole, coord);
        }
        void gotoxy(short x, short y) {
            COORD coord;
            coord.X = x;
            coord.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        }
        void drawMainShell(short StartX = 0,short StartY = 0)
        {
            gotoxy(StartX,StartY);
            std::cout << "\033[32m welcome to V3rfy \n  if you're new here type 'help' to get started\n >>> ";
        }
    public:
        void start()
        {
            clearScreen();
            drawMainShell(0,5);
        }
    };
}

#endif