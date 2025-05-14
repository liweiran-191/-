// ddlparser.cpp
// 此文件实现了 DDLParser 类，用于解析 SQL 中的 DDL 语句
#include "ddlparser.h"
#include <QDebug>

namespace SQL {

// 构造函数，初始化 Parser 引用
DDLParser::DDLParser(Parser& parser) : m_parser(parser) {}

// 解析 SQL 语句，根据关键字调用相应的解析方法
AST::Statement* DDLParser::parse() {
    // 确保当前 token 是 CREATE 或 DROP
    Token firstToken = m_parser.consume(TokenType::KEYWORD, "Expected CREATE or DROP");

    if (firstToken.value == "CREATE") {
        // 解析 CREATE 语句
        return parseCreateStatement();
    } else if (firstToken.value == "DROP") {
        // 解析 DROP 语句
        return parseDropStatement();
    }

    // 抛出异常
    throw m_parser.error(firstToken, "Expected CREATE or DROP");
}

// 解析 CREATE 语句，根据关键字调用相应的解析方法
AST::Statement* DDLParser::parseCreateStatement() {
    Token secondToken = m_parser.consume(TokenType::KEYWORD, "Expected DATABASE or TABLE after CREATE");

    if (secondToken.value == "DATABASE") {
        // 解析创建数据库语句
        return parseCreateDatabase();
    } else if (secondToken.value == "TABLE") {
        // 解析创建表语句
        return parseCreateTable();
    }

    // 抛出异常
    throw m_parser.error(secondToken, "Expected DATABASE or TABLE after CREATE");
}

// 解析 DROP 语句，根据关键字调用相应的解析方法
AST::Statement* DDLParser::parseDropStatement() {
    Token secondToken = m_parser.consume(TokenType::KEYWORD, "Expected DATABASE or TABLE after DROP");

    if (secondToken.value == "DATABASE") {
        // 解析删除数据库语句
        return parseDropDatabase();
    } else if (secondToken.value == "TABLE") {
        // 解析删除表语句
        return parseDropTable();
    }

    // 抛出异常
    throw m_parser.error(secondToken, "Expected DATABASE or TABLE after DROP");
}

// 解析创建数据库语句
AST::CreateDatabaseStatement* DDLParser::parseCreateDatabase() {
    // 创建 CreateDatabaseStatement 对象
    AST::CreateDatabaseStatement* stmt = new AST::CreateDatabaseStatement();
    stmt->databaseName = m_parser.consume(TokenType::IDENTIFIER, "Expected database name after CREATE DATABASE").value;
    m_parser.consume(TokenType::PUNCTUATION, "Expected semicolon after CREATE DATABASE"); // 消耗分号
    return stmt;
}

// 解析删除数据库语句
AST::DropDatabaseStatement* DDLParser::parseDropDatabase() {
    // 创建 DropDatabaseStatement 对象
    AST::DropDatabaseStatement* stmt = new AST::DropDatabaseStatement();
    stmt->databaseName = m_parser.consume(TokenType::IDENTIFIER, "Expected database name after DROP DATABASE").value;
    m_parser.consume(TokenType::PUNCTUATION, "Expected semicolon after DROP DATABASE"); // 消耗分号
    return stmt;
}

// 解析创建表语句
AST::CreateTableStatement* DDLParser::parseCreateTable() {
    // 创建 CreateTableStatement 对象
    AST::CreateTableStatement* stmt = new AST::CreateTableStatement();
    stmt->tableName = m_parser.consume(TokenType::IDENTIFIER, "Expected table name after CREATE TABLE").value;
    m_parser.consume(TokenType::PUNCTUATION, "Expected left parenthesis after table name"); // 消耗左括号
    stmt->columns = parseColumnDefinitions();
    m_parser.consume(TokenType::PUNCTUATION, "Expected right parenthesis after column definitions"); // 消耗右括号

    Token semicolon = m_parser.consume(TokenType::PUNCTUATION, "Expected semicolon after CREATE TABLE statement");
    if (semicolon.value != ";") {
        // 抛出异常
        throw m_parser.error(semicolon, "Expected semicolon after CREATE TABLE statement");
    }

    return stmt;
}

// 解析删除表语句
AST::DropTableStatement* DDLParser::parseDropTable() {
    // 创建 DropTableStatement 对象
    AST::DropTableStatement* stmt = new AST::DropTableStatement();
    stmt->tableName = m_parser.consume(TokenType::IDENTIFIER, "Expected table name after DROP TABLE").value;
    m_parser.consume(TokenType::PUNCTUATION, "Expected semicolon after DROP TABLE"); // 消耗分号
    return stmt;
}

// 解析列定义列表
QList<AST::ColumnDefinition> DDLParser::parseColumnDefinitions() {
    QList<AST::ColumnDefinition> columns;
    while (!m_parser.isAtEnd() && !(m_parser.check(TokenType::PUNCTUATION) && m_parser.peek().value == ")")) {
        // 解析列定义
        columns.append(parseColumnDefinition());
        if (m_parser.check(TokenType::PUNCTUATION) && m_parser.peek().value == ",") {
            m_parser.advance();
            continue;
        } else {
            break;
        }
    }
    return columns;
}

// 解析列定义
AST::ColumnDefinition DDLParser::parseColumnDefinition() {
    AST::ColumnDefinition column;
    column.name = m_parser.consume(TokenType::IDENTIFIER, "Expected column name").value;

    // 解析列类型，处理包含括号的情况
    int start = m_parser.m_current;
    int parenCount = 0; // 记录括号数量
    while (!m_parser.isAtEnd()) {
        Token token = m_parser.peek();
        if (token.type == TokenType::PUNCTUATION) {
            if (token.value == "(") {
                parenCount++;
            } else if (token.value == ")") {
                parenCount--;
                if (parenCount == 0) {
                    m_parser.advance(); // 消耗右括号
                    break;
                }
            } else if (token.value == "," && parenCount == 0) {
                break;
            }
        }
        m_parser.advance();
    }
    QString typeValue;
    for (int i = start; i < m_parser.m_current; ++i) {
        typeValue += m_parser.m_tokens[i].value;
    }
    column.type = typeValue;

    // 检查 PRIMARY KEY 约束
    if (m_parser.check(TokenType::KEYWORD) && m_parser.peek().value == "PRIMARY") {
        m_parser.advance(); // 消耗 PRIMARY
        if (m_parser.check(TokenType::KEYWORD) && m_parser.peek().value == "KEY") {
            m_parser.consume(TokenType::KEYWORD, "Expected KEY after PRIMARY"); // 消耗 KEY
            column.isPrimaryKey = true;
        } else {
            // 如果 KEY 不是关键字，则回退并跳过
            column.isPrimaryKey = false;
        }

    }

    // 检查 NOT NULL 约束
    if (m_parser.check(TokenType::KEYWORD) && m_parser.peek().value == "NOT") {
        m_parser.advance(); // 消耗 NOT
        m_parser.consume(TokenType::KEYWORD, "Expected NULL after NOT"); // 消耗 NULL
        column.isNotNull = true;
    }

    return column;
}


} // namespace SQL
