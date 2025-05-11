#ifndef STATEMENT_H
#define STATEMENT_H

#include <QString>
#include <QList>
#include <QMap>

namespace SQL {
namespace AST {

enum class StatementType {
    CREATE_DATABASE,
    DROP_DATABASE,
    CREATE_TABLE,
    DROP_TABLE,
    INSERT,
    UPDATE,
    DELETE,
    SELECT,
    UNKNOWN
};

struct ColumnDefinition {
    QString name;
    QString type;
    bool isPrimaryKey = false;
    bool isNotNull = false;
    QString defaultValue;
};

struct TableReference {
    QString name;
    QString alias;
};

struct Expression {
    // 表达式基类，可由具体表达式类型继承
    virtual ~Expression() = default;
};

struct LiteralExpression : public Expression {
    QString value;
};

struct ColumnExpression : public Expression {
    QString tableName;
    QString columnName;
};

struct Statement {
    StatementType type;
    virtual ~Statement() = default;
};

struct CreateDatabaseStatement : public Statement {
    QString databaseName;
    CreateDatabaseStatement() { type = StatementType::CREATE_DATABASE; }
};

struct DropDatabaseStatement : public Statement {
    QString databaseName;
    DropDatabaseStatement() { type = StatementType::DROP_DATABASE; }
};

struct CreateTableStatement : public Statement {
    QString tableName;
    QList<ColumnDefinition> columns;
    CreateTableStatement() { type = StatementType::CREATE_TABLE; }
};

struct DropTableStatement : public Statement {
    QString tableName;
    DropTableStatement() { type = StatementType::DROP_TABLE; }
};

// 新增的 AST 节点定义
struct SelectStatement : public Statement {
    QList<ColumnExpression> columns;
    TableReference table;
    Expression* whereClause = nullptr;
    SelectStatement() { type = StatementType::SELECT; }
};

struct InsertStatement : public Statement {
    TableReference table;
    QList<ColumnExpression> columns;
    QList<LiteralExpression> values;
    InsertStatement() { type = StatementType::INSERT; }
};

struct UpdateStatement : public Statement {
    TableReference table;
    QMap<ColumnExpression, LiteralExpression> setValues;
    Expression* whereClause = nullptr;
    UpdateStatement() { type = StatementType::UPDATE; }
};

struct DeleteStatement : public Statement {
    TableReference table;
    Expression* whereClause = nullptr;
    DeleteStatement() { type = StatementType::DELETE; }
};

struct WhereClause : public Expression {
    // 可以根据实际需求添加更多成员
};

} // namespace AST
} // namespace SQL

#endif // STATEMENT_H
