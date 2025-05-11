#include "lexer.h"
#include <QRegularExpression>

Lexer::Lexer(const QString& input) : m_input(input) {}

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

Token Lexer::nextToken() {
    if (m_position >= m_input.length()) {
        return {TokenType::UNKNOWN, "", m_line, m_column};
    }

    QChar current = m_input[m_position];

    // 跳过空白字符
    if (current.isSpace()) {
        return readWhitespace();
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
    static const QString operators = "+-*/%=<>!&|^~";
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

Token Lexer::readWord() {
    int start = m_position;
    while (m_position < m_input.length() && (m_input[m_position].isLetterOrNumber() || m_input[m_position] == '_' || m_input[m_position] == '`')) {
        m_position++;
        m_column++;
    }
    QString value = m_input.mid(start, m_position - start);
    static const QStringList keywords = {"CREATE", "DROP", "DATABASE", "TABLE", "SELECT", "INSERT", "UPDATE", "DELETE", "PRIMARY", "KEY", "NOT", "NULL", "VARCHAR", "INT"};
    TokenType type = keywords.contains(value) ? TokenType::KEYWORD : TokenType::IDENTIFIER; // Removed toUpper()
    return {type, value, m_line, start + 1};
}
Token Lexer::readNumber() {
    int start = m_position;
    while (m_position < m_input.length() && m_input[m_position].isDigit()) {
        m_position++;
        m_column++;
    }
    QString value = m_input.mid(start, m_position - start);
    return {TokenType::NUMBER_LITERAL, value, m_line, start + 1};
}

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

Token Lexer::readOperator() {
    int start = m_position;
    m_position++;
    m_column++;
    return {TokenType::OPERATOR, m_input.mid(start, 1), m_line, start + 1};
}

Token Lexer::readPunctuation() {
    int start = m_position;
    m_position++;
    m_column++;
    return {TokenType::PUNCTUATION, m_input.mid(start, 1), m_line, start + 1};
}

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

Token Lexer::readWhitespace() {
    int start = m_position;
    skipWhitespace();
    QString value = m_input.mid(start, m_position - start);
    return {TokenType::WHITESPACE, value, m_line, start + 1};
}
