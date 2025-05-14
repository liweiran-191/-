#include "database.h"



database::database()
{

}

void database::setName(std::string name)
{
    this->name=name;
}

void database::setPath(std::filesystem::path path)
{
    this->storage_path=path;
}

void database::setTables()
{
    for (const auto& entry : std::filesystem::directory_iterator(this->storage_path)) {
        if (entry.is_regular_file()) {  // 仅处理文件，跳过文件
            this->tables.push_back(entry.path().filename().string());
        }
    }
}

