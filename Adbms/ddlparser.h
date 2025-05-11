#ifndef DDLPARSER_H
#define DDLPARSER_H

#include "parser.h"
#include "statement.h"

namespace SQL {

class DDLParser {
public:
    explicit DDLParser(Parser& parser);
    AST::Statement* parse();

private:
    Parser& m_parser;

    AST::Statement* parseCreateStatement();
    AST::Statement* parseDropStatement();
    AST::CreateDatabaseStatement* parseCreateDatabase();
    AST::DropDatabaseStatement* parseDropDatabase();
    AST::CreateTableStatement* parseCreateTable();
    AST::DropTableStatement* parseDropTable();
    QList<AST::ColumnDefinition> parseColumnDefinitions();
    AST::ColumnDefinition parseColumnDefinition();

};

} // namespace SQL

#endif // DDLPARSER_H
