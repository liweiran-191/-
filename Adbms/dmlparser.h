#ifndef DMLPARSER_H
#define DMLPARSER_H

#include "parser.h"
#include "statement.h"

namespace SQL {

class DMLParser {
public:
    explicit DMLParser(Parser& parser);
    AST::Statement* parse();

private:
    Parser& m_parser;

    AST::SelectStatement* parseSelect();
    AST::InsertStatement* parseInsert();
    AST::UpdateStatement* parseUpdate();
    AST::DeleteStatement* parseDelete();
    AST::TableReference parseTableReference();
    AST::Expression* parseExpression();
    AST::WhereClause* parseWhereClause();
};

} // namespace SQL

#endif // DMLPARSER_H
