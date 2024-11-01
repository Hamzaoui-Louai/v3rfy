#include <iostream>
#include "shell/shell.h"

int main()
{
    Shell::shell shell;
    shell.start();
    std::cin.get();
    return 0;
}