// exception.h
// 此头文件定义了 SQL 解析过程中使用的异常类
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>

namespace SQL {
namespace AST {

// Exception 类继承自 std::runtime_error，用于处理 SQL 解析过程中的异常
class Exception : public std::runtime_error {
public:
    // 构造函数，接收异常信息
    explicit Exception(const std::string& message) : std::runtime_error(message) {}
};

} // namespace AST
} // namespace SQL

#endif // EXCEPTION_H
