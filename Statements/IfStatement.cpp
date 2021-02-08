#include "IfStatement.h"

IfStatement::IfStatement(Expression* expr, Statement* then_condition, Statement* else_condition):
        expr_(expr), then_condition_(then_condition), else_condition_(else_condition) {}

void IfStatement::run() {
    if (std::stoi(expr_->eval())) {
        then_condition_->run();
    } else {
        else_condition_->run();
    }
}