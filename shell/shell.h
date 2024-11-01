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
            COORD coord = { 0, 0 };
            DWORD count;
            DWORD cellCount;

            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(hConsole, &csbi);
            cellCount = csbi.srWindow.Right - csbi.srWindow.Left + static_cast<DWORD>(1) * (csbi.srWindow.Bottom - csbi.srWindow.Top + static_cast<DWORD>(1));
    
            FillConsoleOutputCharacter(hConsole, ' ', cellCount, coord, &count);
            GetConsoleScreenBufferInfo(hConsole, &csbi);
            FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, coord, &count);
            SetConsoleCursorPosition(hConsole, coord);
        }
        void gotoxy(short x, short y) {
            COORD coord;
            coord.X = x;
            coord.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        }
    public:
        void start()
        {
            clearScreen();
            gotoxy(static_cast<short>(0),static_cast<short>(0));
            std::cout << "\033[35m new shell was born today !";
        }
    };
}

#endif