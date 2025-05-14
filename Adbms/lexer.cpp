// lexer.cpp
// 此文件实现了词法分析器类
#include "lexer.h"
#include <QRegularExpression>

// 构造函数，初始化输入的 SQL 语句
Lexer::Lexer(const QString& input) : m_input(input) {}

// 进行词法分析，返回 token 列表
QList<Token> Lexer::tokenize() {
    QList<Token> tokens;

    while (m_position < m_input.length()) {
        Token token = nextToken();
        if (token.type != TokenType::WHITESPACE && token.type != TokenType::COMMENT) {
            tokens.append(token);
        }
    }

    return tokens;
}

// 获取下一个 token
// 获取下一个 token
Token Lexer::nextToken() {
    if (m_position >= m_input.length()) {
        return {TokenType::UNKNOWN, "", m_line, m_column};
    }

    QChar current = m_input[m_position];

    // 跳过空白字符
    if (current.isSpace()) {
        return readWhitespace();
    }

    // 通配符
    if (current == '*') {
        int start = m_position;
        m_position++;
        m_column++;
        return {TokenType::WILDCARD, QString(current), m_line, start + 1};
    }

    // 标识符或关键字
    if (current.isLetter() || current == '_' || current == '`') {
        return readWord();
    }

    // 数字
    if (current.isDigit()) {
        return readNumber();
    }

    // 字符串
    if (current == '\'' || current == '"') {
        return readString();
    }

    // 操作符
    static const QString operators = "+-/%=<>!&|^~"; // 移除 *
    if (operators.contains(current)) {
        return readOperator();
    }

    // 标点符号
    static const QString punctuations = "(),;.";
    if (punctuations.contains(current)) {
        return readPunctuation();
    }

    // 注释
    if (current == '#' || (current == '-' && m_position + 1 < m_input.length() && m_input[m_position + 1] == '-')) {
        return readComment();
    }

    // 未知字符
    Token token{TokenType::UNKNOWN, QString(current), m_line, m_column};
    m_position++;
    m_column++;
    return token;
}

// 跳过空白字符
void Lexer::skipWhitespace() {
    while (m_position < m_input.length() && m_input[m_position].isSpace()) {
        if (m_input[m_position] == '\n') {
            m_line++;
            m_column = 1;
        } else {
            m_column++;
        }
        m_position++;
    }
}

// 读取单词（关键字或标识符）
Token Lexer::readWord() {
    int start = m_position;
    while (m_position < m_input.length() && (m_input[m_position].isLetterOrNumber() || m_input[m_position] == '_' || m_input[m_position] == '`')) {
        m_position++;
        m_column++;
    }
    QString value = m_input.mid(start, m_position - start);
    // 添加聚合函数到关键字列表
    static const QStringList keywords = {"CREATE", "DROP", "DATABASE", "TABLE", "SELECT", "INSERT", "UPDATE", "DELETE", "PRIMARY", "KEY", "NOT", "NULL", "VARCHAR", "INT", "FROM", "WHERE", "GROUP", "BY", "HAVING", "ORDER", "ASC", "DESC", "INNER", "LEFT", "RIGHT", "FULL", "OUTER", "JOIN", "ON", "INTO", "VALUES", "SET", "SUM", "COUNT", "AVG", "MIN", "MAX"};
    TokenType type = keywords.contains(value) ? TokenType::KEYWORD : TokenType::IDENTIFIER;
    qDebug() << "Read word:" << value << "Type:" << static_cast<int>(type); // 添加调试信息
    return {type, value, m_line, start + 1};
}

// 读取数字
Token Lexer::readNumber() {
    int start = m_position;
    while (m_position < m_input.length() && m_input[m_position].isDigit()) {
        m_position++;
        m_column++;
    }
    QString value = m_input.mid(start, m_position - start);
    return {TokenType::NUMBER_LITERAL, value, m_line, start + 1};
}

// 读取字符串
Token Lexer::readString() {
    QChar quote = m_input[m_position];
    int start = m_position++;
    m_column++;
    while (m_position < m_input.length() && m_input[m_position] != quote) {
        if (m_input[m_position] == '\n') {
            m_line++;
            m_column = 1;
        } else {
            m_column++;
        }
        m_position++;
    }
    if (m_position < m_input.length()) {
        m_position++;
        m_column++;
    }
    QString value = m_input.mid(start + 1, m_position - start - 2);
    return {TokenType::STRING_LITERAL, value, m_line, start + 1};
}

// 读取操作符
Token Lexer::readOperator() {
    int start = m_position;
    m_position++;
    m_column++;
    return {TokenType::OPERATOR, m_input.mid(start, 1), m_line, start + 1};
}

// 读取标点符号
Token Lexer::readPunctuation() {
    int start = m_position;
    m_position++;
    m_column++;
    return {TokenType::PUNCTUATION, m_input.mid(start, 1), m_line, start + 1};
}

// 读取注释
Token Lexer::readComment() {
    int start = m_position;
    if (m_input[m_position] == '#' || (m_input[m_position] == '-' && m_input[m_position + 1] == '-')) {
        while (m_position < m_input.length() && m_input[m_position] != '\n') {
            m_position++;
            m_column++;
        }
    }
    QString value = m_input.mid(start, m_position - start);
    return {TokenType::COMMENT, value, m_line, start + 1};
}

// 读取空白字符
Token Lexer::readWhitespace() {
    int start = m_position;
    skipWhitespace();
    QString value = m_input.mid(start, m_position - start);
    return {TokenType::WHITESPACE, value, m_line, start + 1};
}
