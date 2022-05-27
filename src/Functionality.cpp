#include "../include/Functionality.hpp"
#include <iostream>

namespace Login
{
    void Functionality::AddUser(std::pair<std::string, std::string> User)
    {
        Database->insert({User, ""});
    }

    void Functionality::SetAdmin(std::pair<std::string, std::string> User)
    {
        *Admin = User;
    }

    void Functionality::SetMessage(const std::string &m, std::pair<std::string, std::string> User)
    {
        auto it = Database->find(User);
        if(it != Database->end()){ it->second = m; }
    }

    std::string Functionality::GetMessage(std::pair<std::string, std::string> User)
    {
        auto it = Database->find(User);
        if(it != Database->end()){ return it->second; }
    }

    bool Functionality::AttemptLogin(std::pair<std::string, std::string> User)
    {
        auto it = Database->find(User);
        if(it != Database->end()){ return true; }
        else { return false; }
    }

    bool Functionality::CheckAminPrivilege(std::pair<std::string, std::string> User)
    {
        if(User == *Admin){ return true; }
        else { return false; }
    }

    void Functionality::ViewUsers()
    {
        for(auto i : *Database){ std::cout << i.first.first << "\n"; }
    }

    void Functionality::DeleteUser(const std::string& Username)
    {
        for(auto i : *Database)
        {
            if(i.first.first == Username){ Database->erase(i.first); break; }
        }
    }
}