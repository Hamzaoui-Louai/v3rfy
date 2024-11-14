#include <iostream>
#include "shell/shell.h"

int main()
{
    short OldShellWidth;
    short NewShellWidth;
    short OldShellHeight;
    short NewShellHeight;
    Shell::shell shell;
    shell.start();
    shell.getShellDimensions(OldShellWidth,OldShellHeight);
    while(true)
    {
        shell.getShellDimensions(NewShellWidth,NewShellHeight);
        if(NewShellHeight!=OldShellHeight || NewShellWidth!=OldShellWidth)
        {
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif
            shell.Render();
        }
        shell.getShellDimensions(OldShellWidth,OldShellHeight);
        Sleep(5);
    }
    return 0;
}