#include "user.h"
#include<iostream>
#include "database.h"
#include <QJsonObject>    // JSON对象操作
#include <QJsonDocument>  // JSON文档序列化
#include <QFile>          // 文件操作
#include <QCryptographicHash> // 密码加密

// User g_user;

User::User()
{

}

User::User(std::string name,std::string password) {

    //用户名和密码
    this->name=name;
    this->password=password;

    //检查并创建User文件夹，即存放各个用户的信息的文件夹
    std::filesystem::path userPath=std::filesystem::current_path() / "user";
    if(!std::filesystem::exists(userPath)){
        bool success =std::filesystem::create_directory(userPath);
        if(success) std::cout<<"userPath build successfully!";
    }
    //在用户文件夹下为指定用户创建文件夹
    this->storage_path=userPath / this->name;
    if(!std::filesystem::exists(this->storage_path)){
        bool success = std::filesystem::create_directory(this->storage_path);
        if(success) std::cout<<"user "+this->name+" build successfully!";
    }

    //用Qt自带库在指定用户文件夹下创建配置json文件，存储账号密码
    // 🌟 在构造函数末尾添加：
    // 构建JSON对象
    QJsonObject config;
    config["username"] = QString::fromStdString(this->name);
    config["password_hash"] = QString::fromStdString(this->password);
    config["created_at"] = QDateTime::currentDateTime().toString(Qt::ISODate);

    // 序列化JSON
    QJsonDocument doc(config);
    QString configPath = QString::fromStdString(
        (this->storage_path / "user_config.json").string()
        );

    // 写入文件
    QFile configFile(configPath);
    if (configFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        configFile.write(doc.toJson(QJsonDocument::Indented)); // 格式化输出
        configFile.close();
    } else {
        std::cerr << "配置文件创建失败: "
                  << configFile.errorString().toStdString()
                  << std::endl;
    }
}

User::User(std::string name, std::string password, std::filesystem::__cxx11::path path)
{
    this->name=name;
    this->password=password;
    this->storage_path=path;
    //向dbnames中添加表空间名称
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_directory()) {  // 判断是否为文件夹
            this->dbnames.push_back(entry.path().filename().string());  // 提取名称
        }
    }

}
void User::setName(std::string name)
{
    this->name=name;
}

void User::setPass(std::string password)
{
    this->password=password;
}

void User::setStorage_path(std::filesystem::path path)
{
    this->storage_path=path;
}

void User::setDbnames(std::string name)
{
    this->dbnames.push_back(name);
}

void User::createDatabase(std::string dbname)
{
    if(this->has_db(dbname)){
        //说明已经有了这个名字的database
        qDebug()<<"the database has been set!";
        return;
    }
    else{
        //为database建立文件夹
        std::filesystem::path DataBasePath=this->storage_path / dbname;
        if(!std::filesystem::exists(DataBasePath)){
            bool success =std::filesystem::create_directory(DataBasePath);
            if(success) std::cout<<"DatabasePath build successfully!";
        }
        //向dbnames里添加这个数据库名
        this->dbnames.push_back(dbname);

    }
    return;
}

void User::dropDatabase(std::string dbname)
{
    //先检查有无这个文件夹，如有则删除
    try {
        if (this->has_db(dbname) && std::filesystem::is_directory(this->storage_path / dbname)) {
            std::filesystem::remove_all(this->storage_path / dbname);  // 递归删除所有子目录和文件
            this->dbnames.erase(std::remove(this->dbnames.begin(), this->dbnames.end(), "test"), this->dbnames.end());
            return;
        }
        else{
            qDebug()<<"the database not exists!";
            return;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error" << e.what() << std::endl;
        return;
    }
}

database User::getDatabase(std::string dbname)
{
    if(this->has_db(dbname)){
        database newdb;
        newdb.setName(dbname);
        newdb.setPath(this->storage_path / dbname);
        newdb.setTables();
        return newdb;
    }
    else{
        qDebug()<<"database not found";
        throw std::runtime_error("Database not found");
    }
}

bool User::has_db(std::string name)
{
    auto it = std::find(this->dbnames.begin(), this->dbnames.end(),name);
    if (it != this->dbnames.end()) {
        return true;
    } else {
        return false;
    }
}

void UserManager::setUser(const User& user)
{
    g_user = user;
}

User& UserManager::getUser()
{
    return g_user;
}
