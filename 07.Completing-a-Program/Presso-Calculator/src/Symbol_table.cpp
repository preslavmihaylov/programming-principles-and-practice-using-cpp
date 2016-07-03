#include <cassert>

#include "../headers/Utilities.h"
#include "../headers/Symbol_table.h"

Symbol_table::Symbol_table()
{
    this->symbolTable["PI"] = Variable("PI", 3.14159265358979323846, true);
    this->symbolTable["E"] = Variable("E", 2.71828183, true);
};

double Symbol_table::get_value(string id)
{
    if (this->contains(id))
    {
        return this->symbolTable[id].value;
    }
    else
    {
        assert(false);
    }

}

void Symbol_table::set_value(string id, double value)
{
    if (!this->contains(id))
    {
        this->symbolTable[id] = Variable(id);
    }

    this->symbolTable[id].value = value;
}

void Symbol_table::set_const(string id)
{
    if (!this->contains(id))
    {
        throw runtime_error("Undeclared variable " + id);
    }

    this->symbolTable[id].is_constant = true;
}

bool Symbol_table::contains(string id)
{
    return this->symbolTable.find(id) != this->symbolTable.end();
}

bool Symbol_table::is_constant(string id)
{
    if (this->contains(id))
    {
        return this->symbolTable[id].is_constant;
    }
    else
    {
        assert(false);
    }
}
