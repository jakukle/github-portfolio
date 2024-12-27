#include "Calculator.hpp"
#include <cmath>

Calculator::Calculator() {}

Calculator::~Calculator() {}

void Calculator::add(double x, double y) {
    result = x + y;
}

void Calculator::subtract(double x, double y) {
    result = x - y;
}

void Calculator::multiply(double x, double y) { 
    result = x * y;
}

Calculator::Status Calculator::divide(double x, double y) {
    if (y == 0.0) {
        return Calculator::Status::DivisionByZero;
    }
    result = x / y;
    return Calculator::Status::Success;
}

double Calculator::get_result() {
    return result;
}

Calculator::Status Calculator::square_function_roots (
    double a, double b, double c,
    double& x1, double& x2
) {
    Calculator::Status error=Status::NoRoots;
    if (a == 0.0) 
    {
        if (b == 0.0)
            error = Status::ConstansFunction;
        else
        {
            error = Status::LinearFunction;
            x1 = -c / b;
        }
    }
    else
    {
        double delta;
        delta = (b * b) - (4 * a * c);
        if (delta < 0.0)
        {
            error = Status::NoRoots;
        }
        else if (delta == 0.0)
        {
            error = Status::OneRoot;
            x1 = -b / (2 * a);
        }
        else
        {
            error = Status::TwoRoots;
            x1 = ((-b + sqrt(delta)) / (2 * a));
            x2 = ((-b - sqrt(delta)) / (2 * a));
        }
    }
  return error;
}
