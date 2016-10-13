#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <map>

#include "Utilities.h"

#include "Variable.h"

using namespace std;

#define SYMBOL_TABLE (Symbol_table::GetInstance())

class Symbol_table
{
public:
    double get_value(string id);
    void set_value(string id, double value);
    void set_const(string id);
    bool is_constant(string id);
    bool contains(string id);

    static Symbol_table& GetInstance()
    {
        static Symbol_table instance;
        return instance;
    };

    // Deleted methods due to Singleton
    Symbol_table(Symbol_table const&)    = delete;
    void operator=(Symbol_table const&)  = delete;
private:
    Symbol_table();
    map<string, Variable> symbolTable;
};

#endif // SYMBOL_TABLE_H
