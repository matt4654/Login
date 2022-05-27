#include "../include/LoginApp.hpp"

namespace Login
{
    void LoginApp::Run()
    {
        while(true)
        {
            UserInterface.MainMenu();
        }
    }
}