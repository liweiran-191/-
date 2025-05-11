#include "dmlparser.h"

namespace SQL {

DMLParser::DMLParser(Parser& parser) : m_parser(parser) {}

AST::Statement* DMLParser::parse() {
    return nullptr;
}

AST::SelectStatement* DMLParser::parseSelect() {
    return nullptr;
}

AST::InsertStatement* DMLParser::parseInsert() {
    return nullptr;
}

AST::UpdateStatement* DMLParser::parseUpdate() {
    return nullptr;
}

AST::DeleteStatement* DMLParser::parseDelete() {
    return nullptr;
}

AST::TableReference DMLParser::parseTableReference() {
    return {};
}

AST::Expression* DMLParser::parseExpression() {
    return nullptr;
}

AST::WhereClause* DMLParser::parseWhereClause() {
    return nullptr;
}

} // namespace SQL
