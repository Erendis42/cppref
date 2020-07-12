#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int CountDoubleSquares(int n);
vector<vector<int>> GenerateSubsets(int n);
void ReadFile(ifstream& infile, int& numberOfIntegers, vector<int>& vectorOfIntegers);

int main(int argc, char* argv[])
{
    //    if (argc == 2) {
    //string filename = argv[1];
    //string filename = ".\\double_squares_sample_input.txt";
    //string filename = ".\\double_squares.txt";
    string filename = ".\\double_squares_input.txt";
    ifstream infile(filename);

    //int input[] = {10, 25, 3, 0, 1};

    int numberOfIntegers = 0;
    vector<int> input;

    ReadFile(infile, numberOfIntegers, input);

    for (int i = 0; i < 5; i++)
    {
        if (input[i] == 0)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << CountDoubleSquares(input[i]) << endl;
        }
    }

    infile.close();

    /*   }
     else
     {
       cout << "Wrong number of parameters!" << endl;
     }
    */

    return 0;
}

int CountDoubleSquares(int n)
{
    vector<vector<int>> subsets = GenerateSubsets(n);
    int counter = 0;

    for (vector<int> pair: subsets)
    {
        int a = pair[0];
        int b = pair[1];

        if (pow(a, 2) + pow(b, 2) == n)
        {
            //cout << a << "^2 + " << b << "^2 = " << n << endl;
            counter++;
        }
    }

    return counter;
}

vector<vector<int>> GenerateSubsets(int n) {
    vector<vector<int>> subsets;
    vector<int> pair;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n+1; j++)
        {
            pair.clear();
            pair.push_back(i);
            pair.push_back(j);
            subsets.push_back(pair);
        }
    }

    return subsets;
}

void ReadFile(ifstream& infile, int& numberOfIntegers, vector<int>& input)
{
    int number = 0;
    if (infile.is_open()) {
        bool first = true;
        while (infile >> number)
        {
            if (!first) {
                input.push_back(number);
            }
            else
            {
                first = false;
            }
        }
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}
