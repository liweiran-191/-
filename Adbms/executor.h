// executor.h
// 此头文件定义了 Executor 类，用于执行解析后的 SQL 语句
#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "statement.h"

namespace SQL {

// Executor 类负责执行解析后的 SQL 语句
class Executor {
public:
    // 构造函数
    Executor();
    // 执行解析后的 SQL 语句
    void execute(AST::Statement* stmt);

private:
    // 执行创建数据库操作
    void executeCreateDatabase(AST::CreateDatabaseStatement* stmt);
    // 执行删除数据库操作
    void executeDropDatabase(AST::DropDatabaseStatement* stmt);
    // 执行创建表操作
    void executeCreateTable(AST::CreateTableStatement* stmt);
    // 执行删除表操作
    void executeDropTable(AST::DropTableStatement* stmt);
    // 执行插入数据操作
    void executeInsert(AST::InsertStatement* stmt);
    // 执行更新数据操作
    void executeUpdate(AST::UpdateStatement* stmt);
    // 执行删除数据操作
    void executeDelete(AST::DeleteStatement* stmt);
    // 执行查询数据操作
    void executeSelect(AST::SelectStatement* stmt);
};

} // namespace SQL

#endif // EXECUTOR_H
