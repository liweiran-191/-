#ifndef USER_H
#define USER_H
#include "unordered_map"
#include <string>
#include "database.h"
#include <filesystem>
class User
{
public:
    User(std::string,std::string);//创建用户
private:
    std::string name;
    std::string password;
    std::unordered_map<std::string,database*> databases;
    std::filesystem::path storage_path;
};

#endif // USER_H
