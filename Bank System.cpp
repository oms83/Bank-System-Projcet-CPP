// Omer MEMES


#include <iostream>
#include"clsShowLoginScreen.h"
int main()
{
    //clsFindClientScreen::FindClinet();
    //clsMainMenueScreen::ShowMainMenueScreen();
    while (true)
    {
        if (!clsShowLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }
}

//(gci - include * .cs, *.cpp, *.h, *.idl, *.asmx - recurse | select - string .).Count

