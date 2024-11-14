#ifndef SHELL
#define SHELL

#include <Windows.h>
#include <iostream>
#include <string>
#include "toolsbar.h"

namespace bonus
{
    std::string split(std::string Str,char Chr,int sliced) 
    {
        std::string result = "";
        int N = 0;
        for(int i=0;i<(static_cast<int>(Str.length()));i++)
        {
            if(Str[i] == Chr)
            {
                N++;   
                continue;             
            }           
            if(N == sliced)
            {
                result += Str[i];
            }
            if(N > sliced)
            {
                break;
            }
        }
        return result;
    }
};

namespace Shell
{
    class shell{
    private:
        //tools
        toolsbar ToolsBar;
        //shell functions
        
        void gotoxy(short x, short y) 
        {
            COORD coord;
            coord.X = x;
            coord.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        }
        /*void drawMainShell(short StartX = 0,short StartY = 0)
        {
            gotoxy(StartX,StartY);
            std::cout << "\033[32m welcome to V3rfy \n  if you're new here type 'help' to get started\n >>> ";
        }
        void drawToolsBar(short StartX = 0,short StartY = 0,short EndX = 0, short EndY = 0)
        {
            
        }
        */
        void drawIntro(short StartX = 0,short StartY = 0,short EndX = 100, short EndY = 25)
        {
            std::string Logo[] = {"         ___   ______                   ___           ","        /  /  |___   \\    __   ___     /  _|          ","___    /  /     __\\   |  |  |_/  /   _|  |_   __    __","\\  \\  /  /     |___  <   |   ___/   |_    _|  \\ \\  / /"," \\  \\/  /      ____\\  \\  |  |         |  |     \\ \\/ / ","  \\____/      |_______/  |__|         |__|      \\  /  ","                                                / /   ","                                               /_/    "};
            std::cout<<"\033[32m";
            for(short i=0;i<8;i++)
            {
                for(short j=0;j<Logo[i].length();j++)
                {
                    Sleep(10);
                    gotoxy(j+(EndX-StartX)/2-Logo[i].length()/2,i+(EndY-StartY)/2-4);
                    std::cout << Logo[i][j];               
                }
            }
            Sleep(5000);
        }
    public:
        short ShellLeft;
        short ShellRight;
        short ShellTop;
        short ShellBottom;
        short ShellWidth;
        short ShellHeight;
        std::string RenderPipeline[50]; 
        void clearRenderPipeline()
        {
            for(short i;i<50;i++)
            {
                RenderPipeline[i] = "";                
            }
        }
        void clearScreen() 
        {
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif
        }
        void Render()
        {
            getShellCorners(ShellLeft,ShellTop,ShellRight,ShellBottom);    
            getShellDimensions(ShellWidth,ShellHeight);
            std::string tool;
            std::string L,T,R,B;
            short Left,Top,Right,Bottom;
            for(short i = 0;i<50;i++)
            {
                tool = bonus::split(RenderPipeline[i],';',0);
                L = bonus::split(RenderPipeline[i],';',1);
                T = bonus::split(RenderPipeline[i],';',2);
                R = bonus::split(RenderPipeline[i],';',3);
                B = bonus::split(RenderPipeline[i],';',4);
                if(bonus::split(L,'|',1) == "%")
                {
                    if(std::stoi(bonus::split(L,'|',0)) == 0)
                    {
                        Left = ShellLeft;
                    }
                    else
                    {
                    Left = ShellLeft + ShellWidth * std::stoi(bonus::split(L,'|',0)) / 100;
                    }
                }
                if(bonus::split(T,'|',1) == "%")
                {
                    if(std::stoi(bonus::split(T,'|',0)) == 0)
                    {
                        Top = ShellTop;
                    }
                    else
                    {
                        Top = ShellTop + ShellHeight * std::stoi(bonus::split(T,'|',0)) / 100;
                    }
                }
                if(bonus::split(R,'|',1) == "%")
                {
                    if(std::stoi(bonus::split(R,'|',0)) == 0)
                    {
                        Right = ShellLeft;
                    }
                    else
                    {
                        Right = ShellLeft + ShellWidth * std::stoi(bonus::split(R,'|',0)) / 100;
                    }
                }
                if(bonus::split(B,'|',1) == "%")
                {
                    if(std::stoi(bonus::split(B,'|',0)) == 0)
                    {
                        Bottom = ShellTop;
                    }
                    else
                    {
                        Bottom = ShellTop + ShellHeight * std::stoi(bonus::split(B,'|',0)) / 100;
                    }
                }
                if(tool == "ToolsBar")
                {
                    ToolsBar.render(Left,Top,Right,Bottom);
                }
            }
            
        }
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
            //drawToolsBar(100,0,120,30);
            //drawMainShell(0,1);  
            getShellCorners(ShellLeft,ShellTop,ShellRight,ShellBottom);    
            getShellDimensions(ShellWidth,ShellHeight);
            drawIntro(ShellLeft,ShellTop,ShellRight,ShellBottom);
            clearScreen();
            clearRenderPipeline();
            RenderPipeline[0] = "ToolsBar;80|%;0|%;100|%;100|%";
            Render();
            //std::cout<<"holding this shi together";
        }
    };
}

#endif