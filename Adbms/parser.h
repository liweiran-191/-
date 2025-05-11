#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "statement.h"
#include "exception.h"

namespace SQL {

class Parser {
public:
    explicit Parser(const QString& sql);
    AST::Statement* parse();
    AST::Statement* parseStatement();
    bool match(const QList<TokenType>& types);
    bool check(TokenType type) const;
    bool check(TokenType type1, TokenType type2) const; // 新增接受两个参数的 check 函数
    Token advance();
    Token peek() const;
    Token previous() const;
    bool isAtEnd() const;
    Token consume(TokenType type, const QString& message) {
        if (check(type)) return advance();
        throw error(peek(), message);
    }
    AST::Exception error(const Token& token, const QString& message);
    Lexer m_lexer;
    QList<Token> m_tokens;
    int m_current = 0;

protected:

private:

};

} // namespace SQL

#endif // PARSER_H
