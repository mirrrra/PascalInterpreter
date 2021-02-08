#pragma once
#include <string>

class Expression {
public:
    virtual std::string eval() const = 0;
};