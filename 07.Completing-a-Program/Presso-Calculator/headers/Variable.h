#ifndef VARIABLE_H
#define VARIABLE_H

class Variable
{
public:
    string id;
    double value;
    bool is_constant;

    Variable(string id, double value, bool is_constant)
        : id(id), value(value), is_constant(is_constant) {};

    Variable(string id, double value)
        : Variable(id, value, false) {};

    Variable(string id)
        : Variable(id, 0, false) {};

    Variable() {};
};

#endif // VARIABLE_H
