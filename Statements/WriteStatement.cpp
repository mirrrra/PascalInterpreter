#include "WriteStatement.h"

WriteStatement::WriteStatement(std::list<Expression*> args, bool need_break):
        args_(args), need_break_(need_break) {}

void WriteStatement::run() {
    for (Expression* expr : args_) {
        std::cout << expr->eval();
    }

    if (need_break_) {
        std::cout << '\n';
    }
}
