#include "WhileStatement.h"

WhileStatement::WhileStatement(Expression* expr, Statement* statement):
        expr_(expr), statement_(statement) {}

void WhileStatement::run() {
    while (std::stoi(expr_->eval())) {
        statement_->run();
    }
}