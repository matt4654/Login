#ifndef FUNCTIONALITY_HPP
#define FUNCTIONALITY_HPP

#include <utility>
#include <memory>
#include <map>

namespace Login
{
    class Functionality
    {
        protected:
            std::shared_ptr<std::map<std::pair<std::string, std::string>, std::string>> Database = std::make_shared<std::map<std::pair<std::string, std::string>, std::string>>();
            std::shared_ptr<std::pair<std::string, std::string>> Admin = std::make_shared<std::pair<std::string, std::string>>();
            void AddUser(std::pair<std::string, std::string>);
            void SetAdmin(std::pair<std::string, std::string>);
            void SetMessage(const std::string&, std::pair<std::string, std::string>);
            std::string GetMessage(std::pair<std::string, std::string>);
            bool AttemptLogin(std::pair<std::string, std::string>);
            bool CheckAminPrivilege(std::pair<std::string, std::string>);
            void ViewUsers();
            void DeleteUser(const std::string&);
    };
}

#endif