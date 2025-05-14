// statement.h
// 此头文件定义了 SQL 语句的抽象语法树（AST）节点
#ifndef STATEMENT_H
#define STATEMENT_H

#include <QString>
#include <QList>
#include <QMap>

namespace SQL {
namespace AST {

// 定义 SQL 语句的类型
enum class StatementType {
    CREATE_DATABASE, // 创建数据库语句
    DROP_DATABASE,   // 删除数据库语句
    CREATE_TABLE,    // 创建表语句
    DROP_TABLE,      // 删除表语句
    INSERT,          // 插入数据语句
    UPDATE,          // 更新数据语句
    DELETE,          // 删除数据语句
    SELECT,          // 查询数据语句
    UNKNOWN          // 未知语句类型
};

// 定义列的定义信息
struct ColumnDefinition {
    QString name;        // 列名
    QString type;        // 列类型
    bool isPrimaryKey = false; // 是否为主键
    bool isNotNull = false;    // 是否为非空
    QString defaultValue;      // 默认值
};

// 定义表的引用信息
struct TableReference {
    QString name;        // 表名
    QString alias;       // 表别名
};

// 表达式基类，可由具体表达式类型继承
struct Expression {
    // 虚析构函数，确保正确释放派生类对象
    virtual ~Expression() = default;
    // 添加纯虚函数 toString
    virtual QString toString() const = 0;
};

// 字面量表达式
struct LiteralExpression : public Expression {
    QString value;       // 字面量值
    QString toString() const override { return value; }
};

// 列表达式，添加了排序方向
struct ColumnExpression : public Expression {
    QString tableName;   // 表名
    QString columnName;  // 列名
    QString sortDirection; // 排序方向（ASC 或 DESC）
    QString aggregateFunction; // 新增：聚合函数名
    bool isAggregate = false; // 添加此成员

    // 重载小于运算符，用于比较列表达式
    bool operator<(const ColumnExpression& other) const {
        if (tableName == other.tableName) {
            return columnName < other.columnName;
        }
        return tableName < other.tableName;
    }

    QString toString() const override {
        if (isAggregate) {
            return aggregateFunction + "(" + columnName + ")";
        }
        return columnName;
    }
};

// 语句基类
struct Statement {
    StatementType type;  // 语句类型
    // 虚析构函数，确保正确释放派生类对象
    virtual ~Statement() = default;
};

// 创建数据库语句
struct CreateDatabaseStatement : public Statement {
    QString databaseName; // 数据库名
    // 构造函数，初始化语句类型
    CreateDatabaseStatement() { type = StatementType::CREATE_DATABASE; }
};

// 删除数据库语句
struct DropDatabaseStatement : public Statement {
    QString databaseName; // 数据库名
    // 构造函数，初始化语句类型
    DropDatabaseStatement() { type = StatementType::DROP_DATABASE; }
};

// 创建表语句
struct CreateTableStatement : public Statement {
    QString tableName;   // 表名
    QList<ColumnDefinition> columns; // 列定义列表
    // 构造函数，初始化语句类型
    CreateTableStatement() { type = StatementType::CREATE_TABLE; }
};

// 删除表语句
struct DropTableStatement : public Statement {
    QString tableName;   // 表名
    // 构造函数，初始化语句类型
    DropTableStatement() { type = StatementType::DROP_TABLE; }
};

// 聚合表达式
struct AggregateExpression : public Expression {
    QString function;    // 聚合函数名，如 SUM, COUNT, AVG 等
    ColumnExpression column; // 列表达式
    QString toString() const override {
        return function + "(" + column.toString() + ")";
    }
};

// GROUP BY 子句
struct GroupByClause {
    QList<ColumnExpression> columns; // 列表达式列表
    QString toString() const {
        QString result;
        for (int i = 0; i < columns.size(); ++i) {
            if (i > 0) {
                result += ", ";
            }
            result += columns[i].toString();
        }
        return result;
    }
};

// 定义 JOIN 类型
enum class JoinType {
    INNER,       // 内连接
    LEFT,        // 左连接
    RIGHT,       // 右连接
    FULL_OUTER   // 全外连接
};

// JOIN 子句
struct JoinClause {
    JoinType type;       // JOIN 类型
    TableReference table; // 表引用
    Expression* condition; // 连接条件
};

// 查询语句，添加了 ORDER BY 子句
struct SelectStatement : public Statement {
    QList<ColumnExpression> columns; // 列表达式列表
    TableReference table;    // 表引用
    std::unique_ptr<Expression> whereClause; // WHERE 子句，使用智能指针管理
    GroupByClause groupByClause; // GROUP BY 子句
    std::unique_ptr<Expression> havingClause; // HAVING 子句，使用智能指针管理
    QList<JoinClause> joinClauses; // JOIN 子句列表
    QList<ColumnExpression> orderByColumns; // ORDER BY 子句，新增
    // 构造函数，初始化语句类型
    SelectStatement() { type = StatementType::SELECT; }

    // 添加 toString 方法
    QString toString() const {
        QString result = "SELECT ";
        for (int i = 0; i < columns.size(); ++i) {
            if (i > 0) {
                result += ", ";
            }
            result += columns[i].toString();
        }
        result += " FROM " + table.name;
        if (whereClause) {
            result += " WHERE " + whereClause->toString();
        }
        if (!groupByClause.columns.isEmpty()) {
            result += " GROUP BY " + groupByClause.toString();
        }
        if (havingClause) {
            result += " HAVING " + havingClause->toString();
        }
        if (!orderByColumns.isEmpty()) {
            result += " ORDER BY ";
            for (int i = 0; i < orderByColumns.size(); ++i) {
                if (i > 0) {
                    result += ", ";
                }
                result += orderByColumns[i].toString();
            }
        }
        return result;
    }
};

// 插入语句
struct InsertStatement : public Statement {
    TableReference table;    // 表引用
    QList<ColumnExpression> columns; // 列表达式列表
    QList<LiteralExpression> values; // 字面量表达式列表
    // 构造函数，初始化语句类型
    InsertStatement() { type = StatementType::INSERT; }
};

// 更新语句
struct UpdateStatement : public Statement {
    TableReference table;    // 表引用
    QMap<ColumnExpression, LiteralExpression> setValues; // SET 子句
    Expression* whereClause = nullptr; // WHERE 子句
    // 构造函数，初始化语句类型
    UpdateStatement() { type = StatementType::UPDATE; }
};

// 删除语句
struct DeleteStatement : public Statement {
    TableReference table;    // 表引用
    Expression* whereClause = nullptr; // WHERE 子句
    // 构造函数，初始化语句类型
    DeleteStatement() { type = StatementType::DELETE; }
};

// WHERE 子句
struct WhereClause : public Expression {
    std::unique_ptr<Expression> condition; // 条件表达式，使用智能指针管理
    QString toString() const override {
        return condition ? condition->toString() : "";
    }
};

// 二元表达式
struct BinaryExpression : public Expression {
    Expression* left;        // 左表达式
    Expression* right;       // 右表达式
    QString op;              // 操作符，如 AND, OR, =, <, > 等
    QString toString() const override {
        return left->toString() + " " + op + " " + right->toString();
    }
};

// 子查询表达式
struct SubqueryExpression : public Expression {
    std::unique_ptr<SelectStatement> subquery; // 子查询语句，使用智能指针管理
    QString toString() const override {
        return "(" + subquery->toString() + ")";
    }
};

} // namespace AST
} // namespace SQL

#endif // STATEMENT_H
