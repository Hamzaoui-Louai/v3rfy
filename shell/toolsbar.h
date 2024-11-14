#ifndef TOOLSBAR
#define TOOLSBAR

#include <Windows.h>
#include <iostream>
#include <string>

class toolsbar
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
        for(short i = StartY;i<EndY;i++)
            {
                gotoxy(StartX,i);
                std::cout << '|';
            }
            gotoxy(StartX+1,StartY);
            std::cout << "\033[1mTools :";
    }
};



#endif