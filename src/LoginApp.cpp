#include "../include/LoginApp.hpp"

namespace Login
{
    void LoginApp::Run()
    {
        while(UserInterface.Active)
        {
            UserInterface.MainMenu();
        }
    }
}