// parser.h
// 此头文件定义了 Parser 类，用于解析 SQL 语句
#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "statement.h"
#include "exception.h"

namespace SQL {

// Parser 类负责解析 SQL 语句
class Parser {
public:
    // 构造函数，接收输入的 SQL 语句
    explicit Parser(const QString& sql);
    // 解析 SQL 语句
    AST::Statement* parse();
    // 解析 SQL 语句，根据语句类型调用相应的解析器
    AST::Statement* parseStatement();
    // 匹配 token 类型列表
    bool match(const QList<TokenType>& types);
    // 检查当前 token 类型是否匹配
    bool check(TokenType type) const;
    // 检查当前和下一个 token 类型是否匹配
    bool check(TokenType type1, TokenType type2) const;
    // 前进到下一个 token
    Token advance();
    // 获取当前 token
    Token peek() const;
    // 获取前一个 token
    Token previous() const;
    // 检查是否到达输入的末尾
    bool isAtEnd() const;
    // 消耗指定类型的 token，若不匹配则抛出异常
    Token consume(TokenType type, const QString& message) {
        if (check(type)) return advance();
        throw error(peek(), message);
    }
    // 抛出异常
    AST::Exception error(const Token& token, const QString& message);
    // 词法分析器对象
    Lexer m_lexer;
    // token 列表
    QList<Token> m_tokens;
    // 当前 token 索引
    int m_current = 0;

protected:

private:

};

} // namespace SQL

#endif // PARSER_H
