#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>

    namespace SQL {
    namespace AST {

    class Exception : public std::runtime_error {
    public:
        explicit Exception(const std::string& message) : std::runtime_error(message) {}
    };

    } // namespace AST
} // namespace SQL

#endif // EXCEPTION_H
