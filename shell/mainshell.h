#ifndef MAINSHELL
#define MAINSHELL

#include <Windows.h>
#include <iostream>
#include <string>

class mainshell
{
    private:
    void gotoxy(short x, short y) 
        {
            COORD coord;
            coord.X = x;
            coord.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        }
    public:
    void render(short StartX,short StartY,short EndX,short EndY)
    {
        gotoxy(StartX,StartY);
        std::cout<<"\033[0m";
        std::cout << "\033[32m welcome to V3rfy \n  if you're new here type 'help' to get started\n >>> ";
    }
};



#endif