// executor.cpp
// 此文件实现了 Executor 类，用于执行解析后的 SQL 语句
#include "executor.h"
#include <QDebug>
#include "global.h"
namespace SQL {

// 构造函数
Executor::Executor() {
    // 初始化数据库连接
}

// 执行解析后的 SQL 语句，根据语句类型调用相应的执行方法
void Executor::execute(AST::Statement* stmt) {
    switch (stmt->type) {
    case AST::StatementType::CREATE_DATABASE: {
        // 动态转换为 CreateDatabaseStatement 类型
        AST::CreateDatabaseStatement* createDbStmt = dynamic_cast<AST::CreateDatabaseStatement*>(stmt);
        if (createDbStmt) {
            // 执行创建数据库操作
            executeCreateDatabase(createDbStmt);
        }
        break;
    }
    case AST::StatementType::DROP_DATABASE: {
        // 动态转换为 DropDatabaseStatement 类型
        AST::DropDatabaseStatement* dropDbStmt = dynamic_cast<AST::DropDatabaseStatement*>(stmt);
        if (dropDbStmt) {
            // 执行删除数据库操作
            executeDropDatabase(dropDbStmt);
        }
        break;
    }
    case AST::StatementType::CREATE_TABLE: {
        // 动态转换为 CreateTableStatement 类型
        AST::CreateTableStatement* createTableStmt = dynamic_cast<AST::CreateTableStatement*>(stmt);
        if (createTableStmt) {
            // 执行创建表操作
            executeCreateTable(createTableStmt);
        }
        break;
    }
    case AST::StatementType::DROP_TABLE: {
        // 动态转换为 DropTableStatement 类型
        AST::DropTableStatement* dropTableStmt = dynamic_cast<AST::DropTableStatement*>(stmt);
        if (dropTableStmt) {
            // 执行删除表操作
            executeDropTable(dropTableStmt);
        }
        break;
    }
    case AST::StatementType::INSERT: {
        // 动态转换为 InsertStatement 类型
        AST::InsertStatement* insertStmt = dynamic_cast<AST::InsertStatement*>(stmt);
        if (insertStmt) {
            // 执行插入数据操作
            executeInsert(insertStmt);
        }
        break;
    }
    case AST::StatementType::UPDATE: {
        // 动态转换为 UpdateStatement 类型
        AST::UpdateStatement* updateStmt = dynamic_cast<AST::UpdateStatement*>(stmt);
        if (updateStmt) {
            // 执行更新数据操作
            executeUpdate(updateStmt);
        }
        break;
    }
    case AST::StatementType::DELETE: {
        // 动态转换为 DeleteStatement 类型
        AST::DeleteStatement* deleteStmt = dynamic_cast<AST::DeleteStatement*>(stmt);
        if (deleteStmt) {
            // 执行删除数据操作
            executeDelete(deleteStmt);
        }
        break;
    }
    case AST::StatementType::SELECT: {
        // 动态转换为 SelectStatement 类型
        AST::SelectStatement* selectStmt = dynamic_cast<AST::SelectStatement*>(stmt);
        if (selectStmt) {
            // 执行查询数据操作
            executeSelect(selectStmt);
        }
        break;
    }
    default:
        // 不支持的语句类型
        qDebug() << "Unsupported statement type";
        break;
    }
}

// 执行创建数据库操作
void Executor::executeCreateDatabase(AST::CreateDatabaseStatement* stmt) {
    qDebug() << "Executing CREATE DATABASE: " << stmt->databaseName;
    // [预留空位] 实际数据库创建逻辑
    g_user.createDatabase(stmt->databaseName.toStdString());
    // TODO: 实现创建数据库的逻辑
}

// 执行删除数据库操作
void Executor::executeDropDatabase(AST::DropDatabaseStatement* stmt) {
    qDebug() << "Executing DROP DATABASE: " << stmt->databaseName;
    // [预留空位] 实际数据库删除逻辑
    g_user.dropDatabase(stmt->databaseName.toStdString());
    // TODO: 实现删除数据库的逻辑
}

// 执行创建表操作
void Executor::executeCreateTable(AST::CreateTableStatement* stmt) {
    qDebug() << "Executing CREATE TABLE: " << stmt->tableName;
    // [预留空位] 实际表创建逻辑
    // TODO: 实现创建表的逻辑
    // 1. 遍历 stmt->columns 获取列定义
    // 2. 生成 CREATE TABLE 语句
    // 3. 执行 SQL 语句
}

// 执行删除表操作
void Executor::executeDropTable(AST::DropTableStatement* stmt) {
    qDebug() << "Executing DROP TABLE: " << stmt->tableName;
    // [预留空位] 实际表删除逻辑
    // TODO: 实现删除表的逻辑
}

// 执行插入数据操作
void Executor::executeInsert(AST::InsertStatement* stmt) {
    qDebug() << "Executing INSERT into table: " << stmt->table.name;
    // [预留空位] 实际插入数据逻辑

    // TODO: 实现插入数据的逻辑
    // 1. 处理 stmt->columns 获取列名列表
    // 2. 处理 stmt->values 获取值列表
    // 3. 生成 INSERT INTO 语句
    // 4. 执行 SQL 语句
}

// 执行更新数据操作
void Executor::executeUpdate(AST::UpdateStatement* stmt) {
    qDebug() << "Executing UPDATE on table: " << stmt->table.name;
    // [预留空位] 实际更新数据逻辑
    // TODO: 实现更新数据的逻辑
    // 1. 处理 stmt->setValues 获取要更新的列和值
    // 2. 处理 stmt->whereClause 获取条件表达式
    // 3. 生成 UPDATE 语句
    // 4. 执行 SQL 语句
}

// 执行删除数据操作
void Executor::executeDelete(AST::DeleteStatement* stmt) {
    qDebug() << "Executing DELETE from table: " << stmt->table.name;
    // [预留空位] 实际删除数据逻辑
    // TODO: 实现删除数据的逻辑
    // 1. 处理 stmt->whereClause 获取条件表达式
    // 2. 生成 DELETE FROM 语句
    // 3. 执行 SQL 语句
}

// 执行查询数据操作
void Executor::executeSelect(AST::SelectStatement* stmt) {
    qDebug() << "Executing SELECT from table: " << stmt->table.name;
    QString selectQuery = "SELECT ";

    // 处理要查询的列和聚合函数
    for (int i = 0; i < stmt->columns.size(); ++i) {
        if (i > 0) {
            selectQuery += ", ";
        }
        selectQuery += stmt->columns[i].toString();
    }

    selectQuery += " FROM " + stmt->table.name;

    // 处理 WHERE 子句
    if (stmt->whereClause) {
        selectQuery += " WHERE " + stmt->whereClause->toString();
    }

    // 处理 GROUP BY 子句
    if (!stmt->groupByClause.toString().isEmpty()) {
        selectQuery += " GROUP BY " + stmt->groupByClause.toString();
    }

    // 处理 HAVING 子句
    if (stmt->havingClause) {
        selectQuery += " HAVING " + stmt->havingClause->toString();
    }

    // 处理 ORDER BY 子句
    if (!stmt->orderByColumns.isEmpty()) {
        selectQuery += " ORDER BY ";
        for (int i = 0; i < stmt->orderByColumns.size(); ++i) {
            if (i > 0) {
                selectQuery += ", ";
            }
            selectQuery += stmt->orderByColumns[i].toString();
        }
    }

    selectQuery += ";";

    qDebug() << "Generated SELECT query: " << selectQuery;
    // [预留空位] 实际查询数据逻辑
    // TODO: 实现查询数据的逻辑
    // 1. 使用数据库连接执行生成的 SELECT 语句
    // 2. 处理查询结果
}

} // namespace SQL
