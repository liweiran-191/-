// parser.cpp
// 此文件实现了 Parser 类，用于解析 SQL 语句
#include "parser.h"
#include "ddlparser.h"
#include "dmlparser.h"
#include <QDebug>

namespace SQL {

// 构造函数，初始化词法分析器并进行词法分析
Parser::Parser(const QString& sql) : m_lexer(sql) {
    m_tokens = m_lexer.tokenize();
    for (const auto& token : m_tokens) {
        qDebug() << "Token:" << token.value << "Type:" << static_cast<int>(token.type);
    }
}

// 解析 SQL 语句，处理异常
AST::Statement* Parser::parse() {
    try {
        return parseStatement();
    } catch (const AST::Exception& e) {
        qDebug() << "解析过程中出现异常: " << QString::fromStdString(e.what());
        return nullptr;
    }
}

// 解析 SQL 语句，根据语句类型调用相应的解析器
AST::Statement* Parser::parseStatement() {
    if (isAtEnd()) return nullptr;

    Token first = peek();

    if (first.type == TokenType::KEYWORD) {
        if (first.value == "CREATE" || first.value == "DROP") {
            // 使用 DDLParser 解析 DDL 语句
            DDLParser ddlParser(*this);
            return ddlParser.parse();
        } else if (first.value == "SELECT" || first.value == "INSERT" ||
                   first.value == "UPDATE" || first.value == "DELETE") {
            // 使用 DMLParser 解析 DML 语句
            DMLParser dmlParser(*this);
            return dmlParser.parse();
        }
    }

    // 抛出异常
    throw error(peek(), "Unsupported SQL statement");
}

// 匹配 token 类型列表
bool Parser::match(const QList<TokenType>& types) {
    for (TokenType type : types) {
        if (check(type)) {
            advance();
            return true;
        }
    }
    return false;
}

// 检查当前 token 类型是否匹配
bool Parser::check(TokenType type) const {
    if (isAtEnd()) return false;
    return peek().type == type;
}

// 检查当前和下一个 token 类型是否匹配
bool Parser::check(TokenType type1, TokenType type2) const {
    if (isAtEnd() || m_current + 1 >= m_tokens.size()) return false;
    return peek().type == type1 && m_tokens[m_current + 1].type == type2;
}

// 前进到下一个 token
Token Parser::advance() {
    if (!isAtEnd()) m_current++;
    return previous();
}

// 获取当前 token
Token Parser::peek() const {
    if (isAtEnd()) return {TokenType::UNKNOWN, "", -1, -1};
    return m_tokens[m_current];
}

// 获取前一个 token
Token Parser::previous() const {
    return m_tokens[m_current - 1];
}

// 检查是否到达输入的末尾
bool Parser::isAtEnd() const {
    return m_current >= m_tokens.size();
}

// 抛出异常
AST::Exception Parser::error(const Token& token, const QString& message) {
    QString errorMessage = QString("Line %1, Column %2: %3").arg(token.line).arg(token.column).arg(message);
    return AST::Exception(errorMessage.toStdString());
}

} // namespace SQL
