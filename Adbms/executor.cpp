// executor.cpp
#include "executor.h"
#include <QDebug>

namespace SQL {

Executor::Executor() {}

void Executor::execute(AST::Statement* stmt) {
    switch (stmt->type) {
    case AST::StatementType::CREATE_DATABASE: {
        AST::CreateDatabaseStatement* createDbStmt = dynamic_cast<AST::CreateDatabaseStatement*>(stmt);
        if (createDbStmt) {
            executeCreateDatabase(createDbStmt);
        }
        break;
    }
    case AST::StatementType::DROP_DATABASE: {
        AST::DropDatabaseStatement* dropDbStmt = dynamic_cast<AST::DropDatabaseStatement*>(stmt);
        if (dropDbStmt) {
            executeDropDatabase(dropDbStmt);
        }
        break;
    }
    case AST::StatementType::CREATE_TABLE: {
        AST::CreateTableStatement* createTableStmt = dynamic_cast<AST::CreateTableStatement*>(stmt);
        if (createTableStmt) {
            executeCreateTable(createTableStmt);
        }
        break;
    }
    case AST::StatementType::DROP_TABLE: {
        AST::DropTableStatement* dropTableStmt = dynamic_cast<AST::DropTableStatement*>(stmt);
        if (dropTableStmt) {
            executeDropTable(dropTableStmt);
        }
        break;
    }
    default:
        qDebug() << "Unsupported statement type";
        break;
    }
}

void Executor::executeCreateDatabase(AST::CreateDatabaseStatement* stmt) {
    qDebug() << "Executing CREATE DATABASE: " << stmt->databaseName;
    // 这里可以添加实际创建数据库的代码
}

void Executor::executeDropDatabase(AST::DropDatabaseStatement* stmt) {
    qDebug() << "Executing DROP DATABASE: " << stmt->databaseName;
    // 这里可以添加实际删除数据库的代码
}

void Executor::executeCreateTable(AST::CreateTableStatement* stmt) {
    qDebug() << "Executing CREATE TABLE: " << stmt->tableName;
    for (const auto& column : stmt->columns) {
        qDebug() << "  Column: " << column.name << " (" << column.type << ")";
    }
    // 这里可以添加实际创建表的代码
}

void Executor::executeDropTable(AST::DropTableStatement* stmt) {
    qDebug() << "Executing DROP TABLE: " << stmt->tableName;
    // 这里可以添加实际删除表的代码
}

} // namespace SQL
