#include "user.h"
#include<iostream>
// 在user.h中添加
#include <QJsonObject>    // JSON对象操作
#include <QJsonDocument>  // JSON文档序列化
#include <QFile>          // 文件操作
#include <QCryptographicHash> // 密码加密
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
