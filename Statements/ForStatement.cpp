#include "ForStatement.h"
#include <stdexcept>

ForStatement::ForStatement(Driver* driver, const std::string &id, Expression* first_expr, Expression* second_expr,
        Statement* statement, bool back_way):
        driver_(driver), id_(id), first_expr_(first_expr),
        second_expr_(second_expr), statement_(statement), back_way_(back_way) {}

void ForStatement::run() {
    for (int i = std::stoi(first_expr_->eval()); eq_(i, std::stoi(second_expr_->eval()), back_way_); change_(i, back_way_)) {
        if (driver_->variables.find(id_) == driver_->variables.end()) {
            throw std::logic_error("Identifier doesn't exist");
        }
        driver_->variables[id_] = std::to_string(i);
        statement_->run();
    }
}

bool ForStatement::eq_ (int a, int b, bool sign) {
    return sign ? a >= b : a <= b;
}

void ForStatement::change_ (int &value, bool sign) {
    if (sign) {
        value--;
    } else {
        value++;
    }
}
