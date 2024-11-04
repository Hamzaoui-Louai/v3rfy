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
        void drawToolsBar(short StartX = 0,short StartY = 0,short EndX = 0, short EndY = 0)
        {
            for(short i = StartY;i<=EndY;i++)
            {
                gotoxy(StartX,i);
                std::cout << '|';
            }
            gotoxy(StartX+1,StartY);
            std::cout << "\033[1mTools :";
        }
    public:
        void getShellCorners(short &Left,short &Top,short &Right,short &Bottom)
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(hConsole, &csbi);
            Left = csbi.srWindow.Left;
            Top = csbi.srWindow.Top;
            Right = csbi.srWindow.Right;
            Bottom = csbi.srWindow.Bottom;
        }
        void getShellDimensions(short &Width,short &Height)
        {
            short Left,Top,Right,Bottom;
            getShellCorners(Left,Top,Right,Bottom);
            Width = Right - Left + 1;
            Height = Bottom - Top + 1;
        }
        void start()
        {
            clearScreen();
            drawToolsBar(100,0,120,30);
            drawMainShell(0,1);         
        }
    };
}

#endif