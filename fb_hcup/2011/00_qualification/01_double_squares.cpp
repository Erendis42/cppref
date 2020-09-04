#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void ReadFile(ifstream& infile, int& numberOfIntegers, vector<int>& input);
int CountSquarePairs(int n);

int main(int argc, char* argv[])
{
    int numberOfIntegers;
    vector<int> input;

    string filename = ".\\input.txt";
    ifstream infile(filename);

    ReadFile(infile, numberOfIntegers, input);

    infile.close();    

    for (int i = 0; i < numberOfIntegers; i++)
    {
        cout << "Case #" << i+1 << ": " << CountSquarePairs(input[i], primes) << endl;
    }    

    return 0;
}

int CountSquarePairs(int n)
{
    if (n <= 2 ) {
        return 1;
        // 0 = 0^2 + 0^2
        // 1 = 0^2 + 1^2
    }
    else {
        int counter = 0;

        for (int i = 0; i <= sqrt(n); i++)
        {
            for (int j = i + 1; j <= sqrt(n); j++)
            {
                if ((i * i + j * j) == n)
                {
                    counter++;
                }
            }
        }

        return counter;
    }
    return 0;
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
                numberOfIntegers = number;
                first = false;
            }
        }
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}
