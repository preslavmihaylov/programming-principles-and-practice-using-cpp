#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

vector<string> variations =
{
    "rock",
    "paper",
    "scissors"
};

bool is_valid_choice(string choice)
{
    return choice == "rock" || choice == "paper" || choice == "scissors";
}

bool is_game_over(string first, string second)
{
    if ((first == "rock" && second == "rock") ||
        (first == "scissors" && second == "scissors") ||
        (first == "paper" && second == "paper"))
    {
        return false;
    }

    return true;
}

bool human_wins(string human_choice, string comp_choice)
{
    if ((human_choice == "rock" && comp_choice == "scissors") ||
        (human_choice == "scissors" && comp_choice == "paper") ||
        (human_choice == "paper" && comp_choice == "rock"))
    {
        return true;
    }

    return false;
}

string pick_comp_choice()
{
    return variations[rand() % variations.size()];
}

int main()
{
    string choice;
    string comp_choice;
    srand(time(NULL));

    while (true)
    {
        cout << "What did you choose? ";
        cin >> choice;
        comp_choice = pick_comp_choice();

        if (!is_valid_choice(choice))
        {
            cout << "I do not understand that" << endl;
            continue;
        }

        if (!is_game_over(choice, comp_choice))
        {
            cout << "TIE! I chose " << comp_choice << endl;
            cout << "try again" << endl;
        }
        else
        {
            break;
        }
    }

    if (human_wins(choice, comp_choice))
    {
        cout << "You win! " << choice << " beats " << comp_choice << "!" << endl;
    }
    else
    {
        cout << "I win! " << comp_choice << " beats " << choice << "!" << endl;
    }

    return 0;
}
