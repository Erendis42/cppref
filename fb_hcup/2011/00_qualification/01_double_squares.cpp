#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void main(int argc, char* argv[]) {

//    if (argc == 2) {

        //string filename = argv[1];
        string filename = ".\\double_squares_sample_input.txt";
        ifstream infile(filename);
        
        int numberOfIntegers = 0;
        vector<int> vectorOfIntegers;

        // read the whole thing
        // number of ints goes to numberOfIntegers, the rest goes into vectorOfIntegers
        ReadFile(infile, numberOfIntegers, vectorOfIntegers);

        // process numbers one by one to count the possible ways to write them as the sum of
        // two square numbers

        for (int i : vectorOfIntegers)
        {
            // probably better with hashmap or something
            vector<int[2]> vectorOfDoublePrimeFactors;
            
            int indexOfFactors;
            int dividend = i;
            int divisor = 0;

            while(dividend > 0)
            {
                // generate prime numbers until its not greater than the number
                // (https://www.programiz.com/cpp-programming/examples/prime-number-intervals)

                // check with loop for power of each prime factor

                // get subsets of 2 numbers with powers greater than or equal to 2

                // count the number of these subsets

                // profit! :)
            }
        }

        infile.close();
 /*   }
      else      
      {
        cout << "Wrong number of parameters!" << endl;
      }
 */
}

void ReadFile(std::ifstream& infile, int& numberOfIntegers, std::vector<int>& integers)
{
    int number = 0;
    if (infile.is_open()) {
        bool first = true;
        while (infile >> number)
        {
            if (first) {
                numberOfIntegers = number;
            }
            else
            {
                integers.push_back(number);
            }
        }
    }
    else
    {
        cout << "file can't be opened" << endl;
    }
}
