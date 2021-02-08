#pragma once

#include "Statement.h"
#include "../driver.hh"

class ForStatement: public Statement {
public:
    ForStatement(Driver* driver, const std::string &id, Expression* first_expr, Expression* second_expr, Statement* statement);
    void run() override;
private:
    std::string id_;
    Expression* first_expr_;
    Expression* second_expr_;
    Statement* statement_;
    Driver* driver_;
};