#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

/*
Implementing the grammar:
    Sentence :
        Noun Verb // e.g., C++ rules
        Sentence Conjunction Sentence // e.g., Birds fly but fish swim
    Conjunction :
        "and"
        "or"
        "but"
    Noun:
        Article "birds"
        Article "fish"
        Article "C++"
        "birds"
        "fish"
        "C++"
    Verb:
        "rules"
        "fly"
        "swim"
*/

/* FUNCTION PROTOTYPES */
bool is_conjunction(string &input);
bool is_noun(string &input);
bool is_verb(string &input);
bool sentence();
bool conjunction();
bool noun();
bool verb();

istringstream * input_stream;

bool is_conjunction(string &input)
{
    if (input == "and" ||
        input == "or" ||
        input == "but")
    {
        return true;
    }

    return false;
}

bool is_noun(string &input)
{
    if (input == "birds" ||
        input == "fish" ||
        input == "C++")
    {
        return true;
    }

    return false;
}

bool is_verb(string &input)
{
    if (input == "rules" ||
        input == "fly" ||
        input == "swim")
    {
        return true;
    }

    return false;
}

bool is_article(string &input)
{
    if (input == "The" ||
        input == "the")
    {
        return true;
    }

    return false;
}

bool sentence()
{
    bool result = noun();
    result = result && verb();
    char dot;

    if (input_stream->eof())
    {
        throw runtime_error("Incomplete sentence");
    }

    *input_stream >> dot;

    while (dot != '.' && result == true)
    {
        input_stream->putback(dot);
        result = result && conjunction();
        result = result && sentence();
        *input_stream >> dot;
    }

    input_stream->putback(dot);

    return result;
}

bool conjunction()
{
    string input;

    if (input_stream->eof())
    {
        throw runtime_error("Incomplete sentence");
    }

    *input_stream >> input;

    if (is_conjunction(input))
    {
        return true;
    }

    return false;
}

bool noun()
{
    string input;

    if (input_stream->eof())
    {
        throw runtime_error("Incomplete sentence");
    }

    *input_stream >> input;

    if (is_article(input))
    {
        *input_stream >> input;
    }

    if (is_noun(input))
    {
        return true;
    }

    return false;
}

bool verb()
{
    string input;

    if (input_stream->eof())
    {
        throw runtime_error("Incomplete sentence");
    }

    *input_stream >> input;

    if (is_verb(input))
    {
        return true;
    }

    return false;
}

int main()
{
    bool result;
    string input;

    while (true)
    {
        try
        {
            cout << "Write your sentence: ";
            getline(cin, input);
            input_stream = new istringstream(input);
            result = sentence();

            if (result == true)
            {
                cout << "Sentence parsed successfully" << endl;
            }
            else
            {
                cout << "Failed parsing sentence" << endl;
            }
        }
        catch (runtime_error& e)
        {
            cerr << e.what() << endl;
            break;
        }
        catch (exception& e)
        {
            cerr << e.what() << endl;
            break;
        }

        delete input_stream;
    }

    return 0;
}
