// dmlparser.cpp
// 此文件实现了 DMLParser 类，用于解析 SQL 中的 DML 语句
#include "dmlparser.h"
#include <QDebug>

namespace SQL {

// 构造函数，初始化 Parser 引用和 m_tokens、m_position
DMLParser::DMLParser(Parser& parser) : m_parser(parser) {
    m_tokens = m_parser.m_tokens;
    m_position = m_parser.m_current;
}


// 解析 SQL 语句，根据语句类型调用相应的解析方法
AST::Statement* DMLParser::parse() {
    if (m_parser.peek().value == "SELECT") {
        // 解析 SELECT 语句
        return parseSelect();
    } else if (m_parser.peek().value == "INSERT") {
        // 解析 INSERT 语句
        return parseInsert();
    } else if (m_parser.peek().value == "UPDATE") {
        // 解析 UPDATE 语句
        return parseUpdate();
    } else if (m_parser.peek().value == "DELETE") {
        // 解析 DELETE 语句
        return parseDelete();
    }
    return nullptr;
}

// 解析 SELECT 语句
AST::SelectStatement* DMLParser::parseSelect() {
    // 创建 SelectStatement 对象
    auto* stmt = new AST::SelectStatement();

    // 解析 SELECT 关键字
    m_parser.consume(TokenType::KEYWORD, "Expected SELECT");

    // 解析列
    stmt->columns = parseSelectColumns();

    // 解析 FROM 子句
    m_parser.consume(TokenType::KEYWORD, "Expected FROM after SELECT columns");
    stmt->table = parseTableReference();

    // 解析 JOIN 子句
    stmt->joinClauses = parseJoinClauses();

    // 解析 WHERE 子句
    if (m_parser.check(TokenType::KEYWORD) && m_parser.peek().value == "WHERE") {
        // 使用 std::move 转移所有权
        stmt->whereClause = std::move(parseWhereClause());
    }

    // 解析 GROUP BY 子句
    if (m_parser.check(TokenType::KEYWORD) && m_parser.peek().value == "GROUP") {
        stmt->groupByClause = parseGroupByClause();
    }

    // 解析 HAVING 子句
    if (m_parser.check(TokenType::KEYWORD) && m_parser.peek().value == "HAVING") {
        // 使用 reset 来管理智能指针
        stmt->havingClause.reset(parseHavingClause());
    }

    // 解析 ORDER BY 子句
    if (m_parser.check(TokenType::KEYWORD) && m_parser.peek().value == "ORDER") {
        stmt->orderByColumns = parseOrderByClause();
    }

    return stmt;
}

// 解析 SELECT 子句中的列
QList<AST::ColumnExpression> DMLParser::parseSelectColumns() {
    QList<AST::ColumnExpression> columns;

    do {
        // 修改检查条件，优先检查WILDCARD类型
        if (m_parser.check(TokenType::WILDCARD)) {
            // 处理通配符 *
            AST::ColumnExpression col;
            col.columnName = "*";
            columns.append(col);
            m_parser.advance();
            qDebug() << "Parsed * wildcard. Next token:" << m_parser.peek().value;

            // 确保下一个标记是FROM
            if (!m_parser.check(TokenType::KEYWORD) || m_parser.peek().value != "FROM") {
                throw m_parser.error(m_parser.peek(), "Expected FROM after *");
            }
            break; // * 后面不应该有更多列
        } else if (m_parser.check(TokenType::IDENTIFIER)) {
            // 解析列表达式
            AST::ColumnExpression col = parseColumnExpression();
            columns.append(col);
        } else if (m_parser.check(TokenType::KEYWORD)) {
            QString keyword = m_parser.peek().value;
            if (keyword == "SUM" || keyword == "COUNT" || keyword == "AVG" || keyword == "MIN" || keyword == "MAX") {
                // 处理聚合函数
                m_parser.advance(); // 消耗聚合函数关键字
                m_parser.consume(TokenType::PUNCTUATION, "Expected '(' after aggregate function"); // 消耗左括号
                AST::ColumnExpression col = parseColumnExpression();
                col.aggregateFunction = keyword; // 记录聚合函数名
                col.isAggregate = true; // 标记为聚合函数
                columns.append(col);
                m_parser.consume(TokenType::PUNCTUATION, "Expected ')' after aggregate function argument"); // 消耗右括号
            } else {
                throw m_parser.error(m_parser.peek(), "Expected column name, * or aggregate function");
            }
        } else {
            throw m_parser.error(m_parser.peek(), "Expected column name, * or aggregate function");
        }

        if (m_parser.check(TokenType::PUNCTUATION) && m_parser.peek().value == ",") {
            m_parser.advance();
        } else {
            break;
        }
    } while (true);

    return columns;
}

// 解析 FROM 子句中的表引用
AST::TableReference DMLParser::parseTableReference() {
    AST::TableReference table;

    table.name = m_parser.consume(TokenType::IDENTIFIER, "Expected table name").value;

    // 解析表别名
    if (m_parser.check(TokenType::KEYWORD) && m_parser.peek().value == "AS") {
        m_parser.advance();
        table.alias = m_parser.consume(TokenType::IDENTIFIER, "Expected table alias").value;
    }

    return table;
}

// 解析表达式
AST::Expression* DMLParser::parseExpression() {
    // 先检查通配符
    if (m_parser.check(TokenType::WILDCARD)) {
        AST::ColumnExpression col;
        col.columnName = "*";
        m_parser.advance();
        return new AST::ColumnExpression(col);
    }

    // 处理聚合函数
    if (m_parser.check(TokenType::KEYWORD)) {
        QString keyword = m_parser.peek().value;
        if (keyword == "SUM" || keyword == "COUNT" || keyword == "AVG" || keyword == "MIN" || keyword == "MAX") {
            auto* aggExpr = new AST::AggregateExpression();
            aggExpr->function = keyword;
            m_parser.advance(); // 消耗聚合函数关键字
            m_parser.consume(TokenType::PUNCTUATION, "Expected '(' after aggregate function"); // 消耗左括号
            aggExpr->column = parseColumnExpression();
            m_parser.consume(TokenType::PUNCTUATION, "Expected ')' after aggregate function argument"); // 消耗右括号
            return aggExpr;
        }
    }

    // 处理子查询
    if (m_parser.check(TokenType::PUNCTUATION) && m_parser.peek().value == "(") {
        m_parser.advance(); // 消耗左括号
        if (m_parser.check(TokenType::KEYWORD) && m_parser.peek().value == "SELECT") {
            // 解析子查询
            AST::SelectStatement* selectStmt = parseSelect();
            auto subquery = std::unique_ptr<AST::SelectStatement>(selectStmt);
            auto* subqueryExpr = new AST::SubqueryExpression();
            subqueryExpr->subquery = std::move(subquery);
            m_parser.consume(TokenType::PUNCTUATION, "Expected right parenthesis after subquery"); // 消耗右括号
            return subqueryExpr;
        }
        m_parser.advance(); // 消耗右括号
    }

    // 原有逻辑
    if (m_parser.check(TokenType::IDENTIFIER)) {
        // 解析列表达式
        AST::ColumnExpression col = parseColumnExpression();
        auto* expr = new AST::ColumnExpression(col);
        *expr = col;
        return expr;
    } else if (m_parser.check(TokenType::STRING_LITERAL) ||
               m_parser.check(TokenType::NUMBER_LITERAL)) {
        // 解析字面量表达式
        auto* expr = new AST::LiteralExpression();
        expr->value = m_parser.advance().value;
        return expr;
    }
    return nullptr;
}

// 解析 WHERE 子句
std::unique_ptr<AST::WhereClause> DMLParser::parseWhereClause() {
    m_parser.consume(TokenType::KEYWORD, "Expected WHERE");
    // 创建 WhereClause 对象
    auto clause = std::make_unique<AST::WhereClause>();
    // 使用 unique_ptr 管理 condition
    clause->condition = std::unique_ptr<AST::Expression>(parseCondition());
    return clause;
}

// 解析 GROUP BY 子句
AST::GroupByClause DMLParser::parseGroupByClause() {
    AST::GroupByClause clause;

    m_parser.consume(TokenType::KEYWORD, "Expected GROUP");
    m_parser.consume(TokenType::KEYWORD, "Expected BY after GROUP");

    do {
        // 解析列表达式
        clause.columns.append(parseColumnExpression());

        if (m_parser.check(TokenType::PUNCTUATION) && m_parser.peek().value == ",") {
            m_parser.advance();
        } else {
            break;
        }
    } while (true);

    return clause;
}

// 解析 HAVING 子句
AST::Expression* DMLParser::parseHavingClause() {
    m_parser.consume(TokenType::KEYWORD, "Expected HAVING");
    // 解析条件表达式
    return parseCondition();
}

// 解析 JOIN 子句
QList<AST::JoinClause> DMLParser::parseJoinClauses() {
    QList<AST::JoinClause> joins;

    while (m_parser.check(TokenType::KEYWORD)) {
        QString joinType = m_parser.peek().value;

        if (joinType == "INNER" || joinType == "LEFT" || joinType == "RIGHT" || joinType == "FULL") {
            // 解析单个 JOIN 子句
            joins.append(parseJoinClause());
        } else {
            break;
        }
    }

    return joins;
}

// 解析单个 JOIN 子句
AST::JoinClause DMLParser::parseJoinClause() {
    AST::JoinClause join;

    // 解析 JOIN 类型
    QString joinType = m_parser.advance().value;
    if (joinType == "INNER") {
        join.type = AST::JoinType::INNER;
    } else if (joinType == "LEFT") {
        join.type = AST::JoinType::LEFT;
    } else if (joinType == "RIGHT") {
        join.type = AST::JoinType::RIGHT;
    } else if (joinType == "FULL") {
        m_parser.consume(TokenType::KEYWORD, "Expected OUTER after FULL");
        join.type = AST::JoinType::FULL_OUTER;
    }

    m_parser.consume(TokenType::KEYWORD, "Expected JOIN");

    // 解析 JOIN 的表
    join.table = parseTableReference();

    // 解析 ON 条件
    m_parser.consume(TokenType::KEYWORD, "Expected ON after JOIN");
    join.condition = parseCondition();

    return join;
}

// 解析 ORDER BY 子句
QList<AST::ColumnExpression> DMLParser::parseOrderByClause() {
    QList<AST::ColumnExpression> columns;

    m_parser.consume(TokenType::KEYWORD, "Expected ORDER");
    m_parser.consume(TokenType::KEYWORD, "Expected BY after ORDER");

    do {
        // 解析列表达式
        AST::ColumnExpression col = parseColumnExpression();

        // 解析排序方向
        if (m_parser.check(TokenType::KEYWORD)) {
            QString direction = m_parser.peek().value;
            if (direction == "ASC" || direction == "DESC") {
                col.sortDirection = direction;
                m_parser.advance();
            }
        }

        columns.append(col);

        if (m_parser.check(TokenType::PUNCTUATION) && m_parser.peek().value == ",") {
            m_parser.advance();
        } else {
            break;
        }
    } while (true);

    return columns;
}

// 解析条件表达式
AST::Expression* DMLParser::parseCondition() {
    // 简单实现 AND/OR 逻辑表达式
    AST::Expression* left = parseExpression();

    while (m_parser.check(TokenType::KEYWORD) || m_parser.check(TokenType::OPERATOR)) {
        QString op = m_parser.peek().value;
        if (op == "AND" || op == "OR" || op == "=" || op == ">" || op == "<" || op == ">=" || op == "<=" || op == "!=") {
            m_parser.advance();
            // 解析右表达式
            AST::Expression* right = parseExpression();

            // 创建二元表达式
            auto* binExpr = new AST::BinaryExpression();
            binExpr->left = left;
            binExpr->right = right;
            binExpr->op = op;

            left = binExpr;
        } else {
            break;
        }
    }

    return left;
}

// 解析列表达式
AST::ColumnExpression DMLParser::parseColumnExpression() {
    AST::ColumnExpression col;

    // 解析表名.列名
    if (m_parser.check(TokenType::IDENTIFIER)) {
        col.tableName = m_parser.advance().value;

        if (m_parser.check(TokenType::PUNCTUATION) && m_parser.peek().value == ".") {
            m_parser.advance();
            col.columnName = m_parser.consume(TokenType::IDENTIFIER, "Expected column name after dot").value;
        } else {
            col.columnName = col.tableName;
            col.tableName.clear();
        }
    }

    return col;
}

// 解析 INSERT 语句
AST::InsertStatement* DMLParser::parseInsert() {
    // 创建 InsertStatement 对象
    auto* stmt = new AST::InsertStatement();

    // 解析 INSERT INTO 关键字
    m_parser.consume(TokenType::KEYWORD, "Expected INSERT");
    m_parser.consume(TokenType::KEYWORD, "Expected INTO after INSERT");

    // 解析表名
    stmt->table = parseTableReference();

    // 解析列名（可选）
    if (m_parser.check(TokenType::PUNCTUATION) && m_parser.peek().value == "(") {
        m_parser.advance(); // 消耗左括号
        do {
            // 解析列表达式
            AST::ColumnExpression col = parseColumnExpression();
            stmt->columns.append(col);

            if (m_parser.check(TokenType::PUNCTUATION) && m_parser.peek().value == ",") {
                m_parser.advance();
            } else {
                break;
            }
        } while (true);
        m_parser.consume(TokenType::PUNCTUATION, "Expected right parenthesis after column names"); // 消耗右括号
    }

    // 解析 VALUES 关键字
    m_parser.consume(TokenType::KEYWORD, "Expected VALUES after table name or column names");

    // 解析插入的值
    m_parser.consume(TokenType::PUNCTUATION, "Expected left parenthesis after VALUES"); // 消耗左括号
    do {
        AST::LiteralExpression value;
        if (m_parser.check(TokenType::STRING_LITERAL) || m_parser.check(TokenType::NUMBER_LITERAL)) {
            value.value = m_parser.advance().value;
            stmt->values.append(value);
        }

        if (m_parser.check(TokenType::PUNCTUATION) && m_parser.peek().value == ",") {
            m_parser.advance();
        } else {
            break;
        }
    } while (true);
    m_parser.consume(TokenType::PUNCTUATION, "Expected right parenthesis after values"); // 消耗右括号

    return stmt;
}

// 解析 UPDATE 语句
AST::UpdateStatement* DMLParser::parseUpdate() {
    // 创建 UpdateStatement 对象
    auto* stmt = new AST::UpdateStatement();

    // 解析 UPDATE 关键字
    m_parser.consume(TokenType::KEYWORD, "Expected UPDATE");

    // 解析表名
    stmt->table = parseTableReference();

    // 解析 SET 子句
    m_parser.consume(TokenType::KEYWORD, "Expected SET after UPDATE");

    do {
        // 解析列表达式
        AST::ColumnExpression col = parseColumnExpression();
        qDebug() << "Parsed column:" << col.columnName;
        if (m_parser.check(TokenType::OPERATOR) && m_parser.peek().value == "=") {
            m_parser.advance();
        } else {
            // 抛出异常
            throw m_parser.error(m_parser.peek(), "Expected '=' after column name");
        }
        AST::LiteralExpression value;
        if (m_parser.check(TokenType::STRING_LITERAL) || m_parser.check(TokenType::NUMBER_LITERAL)) {
            value.value = m_parser.advance().value;
            stmt->setValues.insert(col, value);
        }

        if (m_parser.check(TokenType::PUNCTUATION) && m_parser.peek().value == ",") {
            m_parser.advance();
        } else {
            break;
        }
    } while (true);

    // 解析 WHERE 子句（可选）
    if (m_parser.check(TokenType::KEYWORD) && m_parser.peek().value == "WHERE") {
        stmt->whereClause = parseCondition();
    }

    return stmt;
}

// 解析 DELETE 语句
AST::DeleteStatement* DMLParser::parseDelete() {
    // 创建 DeleteStatement 对象
    auto* stmt = new AST::DeleteStatement();

    // 解析 DELETE FROM 关键字
    m_parser.consume(TokenType::KEYWORD, "Expected DELETE");
    m_parser.consume(TokenType::KEYWORD, "Expected FROM after DELETE");

    // 解析表名
    stmt->table = parseTableReference();

    // 解析 WHERE 子句（可选）
    if (m_parser.check(TokenType::KEYWORD) && m_parser.peek().value == "WHERE") {
        stmt->whereClause = parseCondition();
    }

    return stmt;
}
} // namespace SQL
