#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void ReadFile(std::ifstream& infile, int& numberOfIntegers, std::vector<int>& vectorOfIntegers);
void GeneratePrimes(int& low, int& high, std::vector<int>& primes);

int main(int argc, char* argv[]) {

    //    if (argc == 2) {

        //string filename = argv[1];
    string filename = ".\\double_squares_sample_input.txt";
    //string filename = ".\\double_squares.txt";
    ifstream infile(filename);

    int numberOfIntegers = 0;
    vector<int> vectorOfIntegers;

    ReadFile(infile, numberOfIntegers, vectorOfIntegers);

    vector<int> primes;
    int low, high = 0;

    for (int i : vectorOfIntegers)
    {
        low = high;
        high = i;

        if (high > low) {
            GeneratePrimes(low, high, primes);
        }

        map<int, int> vectorOfPrimeFactors;
        int dividend = i;
        int divisor = 0;

        while (dividend > 0)
        {
            // check with loop for power of each prime factor

            // get subsets of 2 numbers with powers greater than or equal to 0

            // count the number of these subsets

            // profit! :)
        }
    }

    for (int i : primes) {
        cout << i << " ";
    }

    cout << endl;

    infile.close();
    /*   }
         else
         {
           cout << "Wrong number of parameters!" << endl;
         }
    */

    return 0;
}

void ReadFile(std::ifstream& infile, int& numberOfIntegers, std::vector<int>& vectorOfIntegers)
{
    int number = 0;
    if (infile.is_open()) {
        bool first = true;
        while (infile >> number)
        {
            if (first) {
                numberOfIntegers = number;
                first = false;
            }
            else
            {
                vectorOfIntegers.push_back(number);
            }
        }
    }
    else
    {
        cout << "file can't be opened" << endl;
    }
}

// (https://www.programiz.com/cpp-programming/examples/prime-number-intervals)
void GeneratePrimes(int& low, int& high, std::vector<int>& primes)
{
    bool isPrime;

    while (low < high)
    {
        isPrime = true;

        for (int i = 2; i <= low / 2; ++i)
        {
            if (low % i == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            primes.push_back(low);
        }

        ++low;
    }
}