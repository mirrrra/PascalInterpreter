#pragma once

#include "Statement.h"
#include "../driver.hh"

class ForStatement: public Statement {
public:
    ForStatement(Driver* driver, const std::string &id, Expression* first_expr,
            Expression* second_expr, Statement* statement, bool back_way);
    void run() override;
private:
    std::string id_;
    Expression* first_expr_;
    Expression* second_expr_;
    Statement* statement_;
    Driver* driver_;
    bool back_way_;
    bool eq_ (int a, int b, bool sign);
    void change_ (int &value, bool sign);
};