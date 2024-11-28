#ifndef PROJECTHANDLER
#define PROJECTHANDLER

#include <Windows.h>
#include <iostream>
#include <string>

class projecthandler
{
    private:
    bool extended = false;
    std::string projectname = "Project name";
    short center;
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
        center = (EndX - StartX)/2;
        std::cout << "\033[42m";
        for(int i = 0;i<center-projectname.length()/2;i++)
        {
            gotoxy(StartX+i,StartY);
            std::cout<<" ";
        }
        std::cout<<"\033[30m"<<projectname;
        for(int i = center-projectname.length()/2+projectname.length();i<=EndX;i++)
        {
            gotoxy(StartX+i,StartY);
            std::cout<<" ";
        }
    }
};



#endif