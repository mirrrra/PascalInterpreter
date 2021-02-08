#include "ForStatement.h"

ForStatement::ForStatement(Driver* driver, const std::string &id, Expression* first_expr, Expression* second_expr, Statement* statement):
        driver_(driver), id_(id), first_expr_(first_expr), second_expr_(second_expr), statement_(statement) {}

void ForStatement::run() {
    for (int i = std::stoi(first_expr_->eval()); i < std::stoi(second_expr_->eval()); ++i) {
        driver_->variables[id_] = std::to_string(i);
        statement_->run();
    }
}