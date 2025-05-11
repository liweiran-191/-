#include "parser.h"
#include "ddlparser.h"
#include "dmlparser.h"
#include <QDebug>

namespace SQL {

Parser::Parser(const QString& sql) : m_lexer(sql) {
    m_tokens = m_lexer.tokenize();
}

AST::Statement* Parser::parse() {
    try {
        return parseStatement();
    } catch (const AST::Exception& e) {
        qDebug() << "解析过程中出现异常: " << QString::fromStdString(e.what());
        return nullptr;
    }
}

AST::Statement* Parser::parseStatement() {
    if (isAtEnd()) return nullptr;

    Token first = peek();

    if (first.type == TokenType::KEYWORD) {
        if (first.value == "CREATE" || first.value == "DROP") {
            DDLParser ddlParser(*this);
            return ddlParser.parse();
        } else if (first.value == "SELECT" || first.value == "INSERT" ||
                   first.value == "UPDATE" || first.value == "DELETE") {
            DMLParser dmlParser(*this);
            return dmlParser.parse();
        }
    }

    throw error(peek(), "Unsupported SQL statement");
}

bool Parser::match(const QList<TokenType>& types) {
    for (TokenType type : types) {
        if (check(type)) {
            advance();
            return true;
        }
    }
    return false;
}

bool Parser::check(TokenType type) const {
    if (isAtEnd()) return false;
    return peek().type == type;
}

bool Parser::check(TokenType type1, TokenType type2) const {
    if (isAtEnd() || m_current + 1 >= m_tokens.size()) return false;
    return peek().type == type1 && m_tokens[m_current + 1].type == type2;
}

Token Parser::advance() {
    if (!isAtEnd()) m_current++;
    return previous();
}

Token Parser::peek() const {
    if (isAtEnd()) return {TokenType::UNKNOWN, "", -1, -1};
    return m_tokens[m_current];
}

Token Parser::previous() const {
    return m_tokens[m_current - 1];
}

bool Parser::isAtEnd() const {
    return m_current >= m_tokens.size();
}

AST::Exception Parser::error(const Token& token, const QString& message) {
    QString errorMessage = QString("Line %1, Column %2: %3").arg(token.line).arg(token.column).arg(message);
    return AST::Exception(errorMessage.toStdString());
}

} // namespace SQL
