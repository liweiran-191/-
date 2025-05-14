#ifndef TABLE_H
#define TABLE_H
#include<filesystem>
#include<string>
#include<vector>
#include "turple.h"
class Table
{
public:
    Table();


    void insert();
    void update();

private:
    std::filesystem::path tablepath;
    std::string tablename;
    std::vector<std::vector<std::string>> reflection;

    // [
    //     ["atribute1","int"],
    //     ["atribute2","string"]
    // ]

    std::vector<turple*> turplse;
};

#endif // TABLE_H
