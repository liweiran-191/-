#ifndef DATABASE_H
#define DATABASE_H
#include "table.h"
#include "unordered_map"
#include <string>
#include <filesystem>
#include <vector>
class database
{
public:
    database();//创建表空间对象
    void createTable();//在表空间中创建表
    void dropTable();//在表空间中删除表
    void setTables();

    void setName(std::string);
    void setPath(std::filesystem::path);
private:
    std::string name;
    std::filesystem::path storage_path;
    std::vector<std::string> tables;
};

#endif // DATABASE_H
