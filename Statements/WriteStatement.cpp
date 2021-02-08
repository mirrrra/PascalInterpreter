#include "WriteStatement.h"

WriteStatement::WriteStatement(std::list<Expression*> args, bool need_break):
        args_(args), need_break_(need_break) {}

void WriteStatement::run() {
    for (auto it = args_.rbegin(); it != args_.rend(); it++) {
        std::cout << (*it)->eval();
    }

    if (need_break_) {
        std::cout << '\n';
    }
}
