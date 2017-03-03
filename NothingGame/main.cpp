#include <stdio.h>

#include "WindowManager.hpp"

int main(int, char const**)
{
    WindowManager windowManager;
    windowManager.displayLoop();
    
    return 0;
}
