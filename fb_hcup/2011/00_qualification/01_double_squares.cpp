#include <iostream>
#include <vector>

using namespace std;

int CountDoubleSquares(int n);
vector<vector<int>> GenerateSubsets(int n);

vector<int> primes;

int main()
{
    int input[] = {10, 25, 3, 0, 1};

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
