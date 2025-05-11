#ifndef DATABASE_H
#define DATABASE_H
#include "table.h"
#include "unordered_map"
#include <string>
#include <filesystem>
class database
{
public:
    database();//创建表空间
    void createTable();//在表空间中创建表
    void dropTable();//在表空间中删除表
private:
    std::unordered_map<std::string,Table*> tables;
    std::string name;
    std::filesystem::path storage_path;
};

#endif // DATABASE_H
