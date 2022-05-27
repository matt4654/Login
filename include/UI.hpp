#ifndef UI_HPP
#define UI_HPP

#include "Functionality.hpp"

namespace Login
{
    class UI : public Functionality
    {
        public:
            std::pair<std::string, std::string> ReceiveCredentials();
            void MainMenu();
            void UserLogin();
            void CreateAccount();
            void SetAdministrator();
            void AdminLogin();
    };
}

#endif