// lexer.h
// 此头文件定义了词法分析器类
#ifndef LEXER_H
#define LEXER_H

#include <QString>
#include <QList>

// 定义 token 类型
enum class TokenType {
    KEYWORD,       // 关键字
    IDENTIFIER,    // 标识符
    STRING_LITERAL, // 字符串字面量
    NUMBER_LITERAL, // 数字字面量
    OPERATOR,      // 操作符
    PUNCTUATION,   // 标点符号
    COMMENT,       // 注释
    WHITESPACE,    // 空白字符
    UNKNOWN,       // 未知类型
    SEMICOLON,     // 分号
    LEFT_PAREN,    // 左括号
    RIGHT_PAREN,   // 右括号
    COMMA,         // 逗号
    WHERE,          // WHERE 关键字
    WILDCARD       // 通配符
};

// 定义 token 结构体
struct Token {
    TokenType type;  // token 类型
    QString value;   // token 值
    int line;        // token 所在行
    int column;      // token 所在列
};

// 词法分析器类
class Lexer {
public:
    // 构造函数，接收输入的 SQL 语句
    explicit Lexer(const QString& input);
    // 进行词法分析，返回 token 列表
    QList<Token> tokenize();

private:
    QString m_input; // 输入的 SQL 语句
    int m_position = 0; // 当前解析位置
    int m_line = 1;     // 当前行号
    int m_column = 1;   // 当前列号

    // 获取下一个 token
    Token nextToken();
    // 跳过空白字符
    void skipWhitespace();
    // 读取单词（关键字或标识符）
    Token readWord();
    // 读取数字
    Token readNumber();
    // 读取字符串
    Token readString();
    // 读取操作符
    Token readOperator();
    // 读取标点符号
    Token readPunctuation();
    // 读取注释
    Token readComment();
    // 读取空白字符
    Token readWhitespace();
};

#endif // LEXER_H
