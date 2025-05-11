#ifndef LEXER_H
#define LEXER_H

#include <QString>
#include <QList>

enum class TokenType {
    KEYWORD,
    IDENTIFIER,
    STRING_LITERAL,
    NUMBER_LITERAL,
    OPERATOR,
    PUNCTUATION,
    COMMENT,
    WHITESPACE,
    UNKNOWN,
    SEMICOLON,  // 添加分号
    LEFT_PAREN, // 添加左括号
    RIGHT_PAREN, // 添加右括号
    COMMA, // 添加逗号
    WHERE // 新增 WHERE 成员
};

struct Token {
    TokenType type;
    QString value;
    int line;
    int column;
};

class Lexer {
public:
    explicit Lexer(const QString& input);
    QList<Token> tokenize();

private:
    QString m_input;
    int m_position = 0;
    int m_line = 1;
    int m_column = 1;

    Token nextToken();
    void skipWhitespace();
    Token readWord();
    Token readNumber();
    Token readString();
    Token readOperator();
    Token readPunctuation();
    Token readComment();
    Token readWhitespace();
};

#endif // LEXER_H
