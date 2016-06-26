#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <string>

using namespace std;

// local prototypes
int cust_pow(int number, int power);
void generate_rand_letters();
void print_intro();
void print_letters();
bool is_game_over(int bulls);
int digits_cnt(int number);
char get_letter_index(string guess, int index);
void mark_position(int& mask, int index);
bool is_pos_taken(int mask, int index);
void reset_masks();
void calculate_bulls(string number, int& bulls);
void calculate_cows(string number, int& cows);
bool is_char_letter(char ch);
bool string_contains_only_letters(string input);
bool is_valid_input(string input);
bool process_game();
void play_bulls_and_cows();

#define POSITIONS_CNT (4)
#define LETTERS_CNT ('z' - 'a' + 1)

vector<char> letters(POSITIONS_CNT);

// Using binary arithmetic
int target_mask = 0;
int guess_mask = 0;

int cust_pow(int number, int power)
{
    if (power == 0)
    {
        return 1;
    }

    if (power % 2 == 0)
    {
        number = cust_pow(number, power / 2);
        return number * number;
    }

    return number * cust_pow(number, power - 1);
}

void generate_rand_letters()
{
    int seed = time(NULL);
    srand(seed);
    // cout << "DEBUG Seed: " << seed << endl;

    for (int cnt = POSITIONS_CNT - 1; cnt >= 0; --cnt)
    {
        letters[cnt] = rand() % LETTERS_CNT;
    }
}

void print_intro()
{
    cout << "Welcome traveler. Wanna play some bulls and cows? Do your best!" << endl;
}

void print_letters()
{
    cout << "Letters to guess: ";
    for (int cnt = 0; cnt < POSITIONS_CNT; ++cnt)
    {
        cout << (char)(letters[cnt] + 'a');
    }

    cout << endl;
}

bool is_game_over(int bulls)
{
    return (bulls == POSITIONS_CNT);
}

int digits_cnt(int number)
{
    return (int)(log(number) + 1);
}

char get_letter_index(string guess, int index)
{
    return guess[index] - 'a';
}

void mark_position(int& mask, int index)
{
    mask |= (1 << index);
}

bool is_pos_taken(int mask, int index)
{
    return (((mask >> index) & 1) == 1);
}

void reset_masks()
{
    target_mask = 0;
    guess_mask = 0;
}

void calculate_bulls(string number, int& bulls)
{
    int letter_index;

    for (int cnt = 0; cnt < POSITIONS_CNT; ++cnt)
    {
        letter_index = get_letter_index(number, cnt);
        if (letters[cnt] == letter_index)
        {
            mark_position(target_mask, cnt);
            mark_position(guess_mask, cnt);
            ++bulls;
        }
    }
}

void calculate_cows(string guess, int& cows)
{
    int letter_index;

    for (int i = 0; i < POSITIONS_CNT; ++i)
    {
        letter_index = get_letter_index(guess, i);

        if (is_pos_taken(guess_mask, i))
        {
            continue;
        }

        for (int j = 0; j < POSITIONS_CNT; ++j)
        {
            if (letters[j] == letter_index && !is_pos_taken(target_mask, j))
            {
                ++cows;
                mark_position(target_mask, j);
                mark_position(guess_mask, i);
            }
        }
    }
}

bool is_char_letter(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

bool string_contains_only_letters(string input)
{
    for (int cnt = 0; cnt < input.size(); ++cnt)
    {
        if (!is_char_letter(input[cnt]))
        {
            return false;
        }
    }

    return true;
}

bool is_valid_input(string input)
{
    if (string_contains_only_letters(input) && input.size() == POSITIONS_CNT)
    {
        return true;
    }

    return false;
}

bool process_game()
{
    int turns = 0;
    int bulls = 0;
    int cows = 0;
    string guess;

    while (!is_game_over(bulls))
    {
        ++turns;
        bulls = 0;
        cows = 0;
        reset_masks();
        cin >> guess;

        if (!is_valid_input(guess))
        {
            cout << "Invalid input. Try again" << endl;
            continue;
        }

        calculate_bulls(guess, bulls);
        calculate_cows(guess, cows);

        cout << "Bulls: " << bulls << endl;
        cout << "Cows: " << cows << endl;
    }

    cout << "You won! It took you " << turns << " turns." << endl;
    cout << "Wanna try again? (y/n)" << endl;

    while (guess != "y" && guess != "n")
    {
        cin >> guess;

        if (guess == "y")
        {
            return true;
        }
        else if (guess == "n")
        {
            return false;
        }
        else
        {
            cout << "I didn't understand you." << endl;
        }
    }

    return false;
}

void play_bulls_and_cows()
{
    bool continue_game = true;

    while (continue_game)
    {
        continue_game = process_game();
    }
}

int main()
{
    generate_rand_letters();
    print_intro();
    print_letters();
    play_bulls_and_cows();

    return 0;
}
