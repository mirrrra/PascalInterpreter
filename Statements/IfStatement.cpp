#include "IfStatement.h"

IfElseStatement::IfElseStatement(Expression* expr, Statement* then_condition, Statement* else_condition):
        expr_(expr), then_condition_(then_condition), else_condition_(else_condition) {}

void IfElseStatement::run() {
    if (std::stoi(expr_->eval())) {
        then_condition_->run();
    } else {
        else_condition_->run();
    }
}

IfStatement::IfStatement(Expression* expr, Statement* then_condition):
        expr_(expr), then_condition_(then_condition) {}

void IfStatement::run() {
    if (std::stoi(expr_->eval())) {
        then_condition_->run();
    }
}