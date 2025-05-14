#ifndef USER_H
#define USER_H
#include <string>
#include "database.h"
#include <filesystem>
#include <vector>

class User
{
public:
    User();
    User(std::string,std::string);//创建新用户
    User(std::string,std::string,std::filesystem::path);//登录旧用户
    void setName(std::string);
    void setPass(std::string);
    void setStorage_path(std::filesystem::path);
    void setDbnames(std::string);
    void createDatabase(std::string);
    void dropDatabase(std::string);
    database getDatabase(std::string);
    bool has_db(std::string);
    std::vector<std::string> dbnames;
private:
    std::string name;
    std::string password;
    std::filesystem::path storage_path;
};

extern User g_user;

class UserManager
{
public:
    static User& getUser();
    static void setUser(const User& user);
};

#endif // USER_H
