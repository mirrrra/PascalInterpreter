#pragma once

#include "Statement.h"
#include "../driver.hh"

class Assignment: public Statement {
public:
    Assignment(Driver* driver, const std::string& id, Expression* value);
    void run() override;
private:
    std::string id_;
    Expression* value_;
    Driver* driver_;
};