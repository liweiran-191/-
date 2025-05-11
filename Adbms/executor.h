// executor.h
#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "statement.h"

namespace SQL {

class Executor {
public:
    Executor();
    void execute(AST::Statement* stmt);

private:
    void executeCreateDatabase(AST::CreateDatabaseStatement* stmt);
    void executeDropDatabase(AST::DropDatabaseStatement* stmt);
    void executeCreateTable(AST::CreateTableStatement* stmt);
    void executeDropTable(AST::DropTableStatement* stmt);
};

} // namespace SQL

#endif // EXECUTOR_H
