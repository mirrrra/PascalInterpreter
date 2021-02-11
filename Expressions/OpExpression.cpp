#include "OpExpression.h"

BinaryOpExpression::BinaryOpExpression(char op, Expression *exp1, Expression *exp2)
        :op_(op), exp1_(exp1), exp2_(exp2) {}

std::string BinaryOpExpression::eval() const {
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

UnaryOpExpression::UnaryOpExpression(char op, Expression *exp)
        :op_(op), exp_(exp) {}

std::string UnaryOpExpression::eval() const {
    int value = std::stoi(exp_->eval());

    switch (op_) {
        case '-':
            return std::to_string(-value);
        case '!':
            return std::to_string(!value); // not
        default:
            return "";
    }
}