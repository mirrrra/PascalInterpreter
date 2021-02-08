#include "OpExpression.h"

OpExpression::OpExpression(char op, Expression *exp1, Expression *exp2)
        :op_(op), exp1_(exp1), exp2_(exp2) {}

std::string OpExpression::eval() const {
    int first = std::stoi(exp1_->eval());
    int second = std::stoi(exp2_->eval());

    switch (op_) {
        case '+':
            return std::to_string(first + second);
        case '-':
            return std::to_string(first - second);
        case '*':
            return std::to_string(first * second);
        case '/':
            return std::to_string(first / second);
        case '<':
            return std::to_string(first < second);
        case '>':
            return std::to_string(first > second);
        case '=':
            return std::to_string(first == second);
        case '&':
            return std::to_string(first && second); // and
        case '|':
            return std::to_string(first || second); // or
        default:
            return "";
    }
}