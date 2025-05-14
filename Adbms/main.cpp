
#include "mainwindow.h"
// #include "parser.h"
// #include "statement.h"
// #include "exception.h"
#include "login.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login l;
    l.show();
    MainWindow w;
    // w.show();

    return a.exec();
}



// #include <QCoreApplication>
// #include <QDebug>
// #include "parser.h"
// #include "executor.h"

// int main(int argc, char *argv[])
// {
//     QCoreApplication a(argc, argv);

//     // 定义测试用的 SQL 语句列表
//     QStringList sqlStatements = {
//         // DDL 语句
//         "CREATE DATABASE test_db;",
//         "DROP DATABASE test_db;",
//         "CREATE TABLE test_table (id INT PRIMARY KEY, name VARCHAR(255) NOT NULL);",
//         "DROP TABLE test_table;",

//         // DML 语句
//         "INSERT INTO test_table (id, name) VALUES (1, 'John');",
//         "SELECT * FROM test_table;",
//         "SELECT id, name FROM test_table WHERE id = 1;",
//         "SELECT id, name FROM test_table GROUP BY id HAVING id > 0 ORDER BY id ASC;",
//         "UPDATE test_table SET name = 'Jane' WHERE id = 1;",
//         "DELETE FROM test_table WHERE id = 1;"

//         // 包含聚合函数的 SQL 语句
//         "SELECT COUNT(*) FROM test_table;",
//         "SELECT SUM(id) FROM test_table;",
//         "SELECT AVG(id) FROM test_table;",
//         "SELECT MIN(id) FROM test_table;",
//         "SELECT MAX(id) FROM test_table;"
//     };

//     // 遍历 SQL 语句列表进行测试
//     for (const QString& sql : sqlStatements) {
//         qDebug() << "操他妈的测试用例:" << sql;

//         // 创建解析器对象
//         SQL::Parser parser(sql);

//         // 解析 SQL 语句
//         SQL::AST::Statement* stmt = parser.parse();

//         if (stmt) {
//             qDebug() << "哦我的上帝，终于他妈的解析成功了！";

//             // 创建执行器对象
//             SQL::Executor executor;

//             // 执行解析后的语句
//             executor.execute(stmt);

//             // 释放内存
//             delete stmt;
//         } else {
//             qDebug() << "卧槽，怎么解析失败了！";
//         }
//     }
//     return a.exec();
// }
