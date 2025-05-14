// dmlparser.h
// 此头文件定义了 DMLParser 类，用于解析 SQL 中的 DML（数据操作语言）语句，如 SELECT、INSERT、UPDATE 和 DELETE
#ifndef DMLPARSER_H
#define DMLPARSER_H

#include "parser.h"
#include "statement.h"
#include "lexer.h"

namespace SQL {

// DMLParser 类负责解析 SQL 的 DML 语句
class DMLParser {
public:
    // 构造函数，接收一个 Parser 对象的引用
    explicit DMLParser(Parser& parser);
    // 解析 SQL 语句，根据语句类型调用相应的解析方法
    AST::Statement* parse();

    bool check(TokenType type) {
        if (m_position >= m_tokens.size()) return false;
        return m_tokens[m_position].type == type;
    }

private:
    // 引用 Parser 对象，用于词法分析和获取 token
    Parser& m_parser;
    // 新增：当前 token 位置
    int m_position = 0;
    // 新增：token 列表
    QList<Token> m_tokens;

    // 解析 SELECT 语句
    AST::SelectStatement* parseSelect();
    // 解析 INSERT 语句
    AST::InsertStatement* parseInsert();
    // 解析 UPDATE 语句
    AST::UpdateStatement* parseUpdate();
    // 解析 DELETE 语句
    AST::DeleteStatement* parseDelete();

    // 以下是 SELECT 语句相关的解析方法
    // 解析 SELECT 子句中的列
    QList<AST::ColumnExpression> parseSelectColumns();
    // 解析 FROM 子句中的表引用
    AST::TableReference parseTableReference();
    // 解析表达式
    AST::Expression* parseExpression();
    // 解析条件表达式
    AST::Expression* parseCondition();
    // 解析 WHERE 子句
    std::unique_ptr<AST::WhereClause> parseWhereClause();
    // 解析 GROUP BY 子句
    AST::GroupByClause parseGroupByClause();
    // 解析 HAVING 子句
    AST::Expression* parseHavingClause();
    // 解析 JOIN 子句
    QList<AST::JoinClause> parseJoinClauses();
    // 解析单个 JOIN 子句
    AST::JoinClause parseJoinClause();
    // 解析 ORDER BY 子句
    QList<AST::ColumnExpression> parseOrderByClause();
    // 解析列表达式
    AST::ColumnExpression parseColumnExpression();
};

} // namespace SQL

#endif // DMLPARSER_H
