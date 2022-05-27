#include "../include/UI.hpp"
#include <iostream>
#include <conio.h>
#include <functional>

namespace Login
{
    std::pair<std::string, std::string> UI::ReceiveCredentials()
    {
        std::string UN;
        std::cout << "Enter username: ";
        std::cin >> UN;

        std::string PW;
        std::cout << "Enter password: ";
        std::cin >> PW;

        std::pair<std::string, std::string> User(UN, PW);

        return User;
    }

    void UI::MainMenu()
    {
        std::cout << "Welcome!\n";
        std::cout << "1. Login\n";
        std::cout << "2. Create Account\n";
        std::cout << "3. Admin Login\n";
        std::cout << "4. Set Admin\n";

        char input = '0';
        std::cin >> input;
        switch(input)
        {
            case '1':
            {
                UserLogin();
                break;
            }
            case '2':
            {             
                CreateAccount();
                break;
            }
            case '3':
            {
                AdminLogin();
                break;
            }
            case '4':
            {
                SetAdministrator();
                break;
            }
            default:
            {
                system("cls");
                std::cout << "Invalid Entry: Use 1,2,3,4 to select a difficulty" << std::endl;
                std::cout << " " << std::endl;
            }
        }
    }

    void UI::UserLogin()
    {
        auto User = ReceiveCredentials();

        if(AttemptLogin(User)){ std::cout << "Secret message: " << GetMessage(User) << "\n\n"; }
        else{ std::cout << "Login attempt failed. Incorrect username and/or password\n\n"; }

        std::cout << "Press any key to return\n\n";
        getch();
    }

    void UI::CreateAccount()
    {
        auto User = ReceiveCredentials();
        AddUser(User);
        
        std::string msg;
        std::cout << "Enter a secret message: ";
        std::cin >> msg;
        std::cout << "\n";
        SetMessage(msg, User);

        std::cout << "Press any key to return\n\n";
        getch();
    }

    void UI::SetAdministrator()
    {
        auto User = ReceiveCredentials();
        SetAdmin(User);
    }

    void UI::AdminLogin()
    {
        auto User = ReceiveCredentials();
        if(*Admin == User)
        {
            ViewUsers();
            std::string UN;
            std::cout << "Enter username of account you wish to delete: ";
            std::cin >> UN;
            DeleteUser(UN);
            std::cout << "\n";
        }
        else
        {
            std::cout << "Login attempt failed. Incorrect username and/or password\n\n";;
        }

        std::cout << "Press any key to return\n\n";
        getch();
    }
}
