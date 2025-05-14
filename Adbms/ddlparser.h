// ddlparser.h
// 此头文件定义了 DDLParser 类，用于解析 SQL 中的 DDL 语句
#ifndef DDLPARSER_H
#define DDLPARSER_H

#include "parser.h"
#include "statement.h"

namespace SQL {

// DDLParser 类负责解析 SQL 的 DDL 语句
class DDLParser {
public:
    // 构造函数，接收一个 Parser 对象的引用
    explicit DDLParser(Parser& parser);
    // 解析 SQL 语句，根据语句类型调用相应的解析方法
    AST::Statement* parse();

private:
    // 引用 Parser 对象，用于词法分析和获取 token
    Parser& m_parser;

    // 解析 CREATE 语句
    AST::Statement* parseCreateStatement();
    // 解析 DROP 语句
    AST::Statement* parseDropStatement();
    // 解析创建数据库语句
    AST::CreateDatabaseStatement* parseCreateDatabase();
    // 解析删除数据库语句
    AST::DropDatabaseStatement* parseDropDatabase();
    // 解析创建表语句
    AST::CreateTableStatement* parseCreateTable();
    // 解析删除表语句
    AST::DropTableStatement* parseDropTable();
    // 解析列定义列表
    QList<AST::ColumnDefinition> parseColumnDefinitions();
    // 解析列定义
    AST::ColumnDefinition parseColumnDefinition();

};

} // namespace SQL

#endif // DDLPARSER_H
