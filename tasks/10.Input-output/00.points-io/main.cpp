#include <iostream>
#include <stdexcept>
#include <climits>
#include <vector>
#include <fstream>

using namespace std;

struct Point
{
    double x;
    double y;
};

bool operator!=(Point first, Point second)
{
    return (first.x != second.x) ||
           (first.y != second.y);
}

ostream &operator<<(ostream& output, const Point& point)
{
    output << '(' << point.x << ',' << point.y << ')';
    return output;
}

istream &operator>>(istream& input, Point& point)
{
    string line;
    char paran1, comma, paran2;

    input >> paran1;
    if (paran1 != '(')
    {
        throw runtime_error("Invalid parantheses");
    }

    input >> point.x;
    if (input.fail())
    {
        throw runtime_error("Invalid X coordinate");
    }

    input >> comma;
    if (comma != ',')
    {
        throw runtime_error("invalid comma");
    }

    input >> point.y;
    if (input.fail())
    {
        throw runtime_error("Invalid Y coordinate");
    }

    input >> paran2;
    if (paran2 != ')')
    {
        throw runtime_error("Invalid parantheses");
    }

    if (input.bad())
    {
        throw runtime_error("input is corrupted");
    }
    else if (input.fail())
    {
        throw runtime_error("invalid point");
    }

    return input;
}

void ReadInput(vector<Point>& points, istream& inputStream)
{
    int counter;
    for (counter = 0; counter < 7; ++counter)
    {
        Point p;
        try
        {
            inputStream >> p;
            points.push_back(p);
            //cout << p.x << ',' << p.y << endl;
        }
        catch (const runtime_error& e)
        {
            cout << e.what() << endl;

            // clear error flags
            inputStream.clear();

            // flush buffer
            inputStream.ignore(INT_MAX, '\n');
        }
    }
}

void PrintOutput(vector<Point> points, ostream& outputStream)
{
    int counter;
    for (counter = 0; counter < points.size(); ++counter)
    {
        outputStream << points[counter] << endl;
    }
}

void CompareVectors(vector<Point> firstVector, vector<Point> secondVector)
{
    int counter;

    if (firstVector.size() != secondVector.size())
    {
        cout << "Something's wrong!" << endl;
        return;
    }

    for (counter = 0; counter < firstVector.size(); ++counter)
    {
        if (firstVector[counter] != secondVector[counter])
        {
            cout << "Something's wrong!" << endl;
            return;
        }
    }

    cout << "I/O operations completed successfully." << endl;
}

int main()
{
    vector<Point> original_points;
    vector<Point> processed_points;
    ofstream outputFile;
    ifstream inputFile;
    cout << "Input 7 points in the format: (x, y)" << endl;

    ReadInput(original_points, cin);

    outputFile.open("mydata.txt");

    PrintOutput(original_points, outputFile);

    outputFile.close();
    inputFile.open("mydata.txt");

    ReadInput(processed_points, inputFile);

    inputFile.close();

    CompareVectors(original_points, processed_points);

    return 0;
}
