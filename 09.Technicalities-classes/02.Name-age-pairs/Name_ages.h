#ifndef NAME_AGES_H
#define NAME_AGES_H

#include <vector>
#include <string>

class Name_ages
{
public:
    class Invalid {};
    Name_ages()
        : areNamesInput(false), areAgesInput(false) {};
    void ReadNames();
    void ReadAges();
    void Print();
    void Sort();

    friend std::ostream& operator<<(std::ostream& os, const Name_ages& nameAges);
    friend bool operator==(const Name_ages& firstNameAges, const Name_ages& secondNameAges);
    friend bool operator!=(const Name_ages& firstNameAges, const Name_ages& secondNameAges);
private:
    std::vector<std::string> names;
    std::vector<int> ages;
    bool areNamesInput;
    bool areAgesInput;
};

#endif // NAME_AGES_H
