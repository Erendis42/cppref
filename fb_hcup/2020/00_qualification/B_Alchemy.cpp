#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

void ReadFile(ifstream& infile, int& numberOfEntries, vector<string>& input);
void PrintFile(vector<string>& input);
char AssembleShards(string shards);

int main()
{
    string filename = ".\\input.txt";
    ifstream infile(filename);

    int numberOfEntries = 0;
    vector<string> input;

    ReadFile(infile, numberOfEntries, input);

    int n = numberOfEntries;

    for (int i = 0; i < input.size(); i++)
    {
        cout << "Case #" << i+1 << ": " << AssembleShards(input[i]) << endl;
    }

    infile.close();
}

void ReadFile(ifstream& infile, int& numberOfEntries, vector<string>& input)
{
    string line;
    regex r("[[:digit:]]+");
    if (infile.is_open()) {
        while (infile >> line)
        {
            if (!regex_match(line, r)) {
                input.push_back(line);
            }
        }
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}

void PrintFile(vector<string>& input)
{
    for (string l : input)
    {
        cout << l << endl;
    }
}

char AssembleShards(string shards) {
    int length = shards.length();
    int l = 0;
    int r = l+2;

    while (l < r && r < length)
    {
        while (shards[l] == shards[l + 1] && shards[l + 1] == shards[l + 2])
        {
            l++;
            r++;
        }

        if (r < length) {
            int a = 0;
            int b = 0;

            for (int i = 0; i < 3; i++)
            {
                if (shards[i] == 'A') { a++; }
                if (shards[i] == 'B') { b++; }
            }

            if (a > b) { shards[l] = 'A'; }
            if (a < b) { shards[l] = 'B'; }

            for (int i = l + 1; i < length; i++)
            {
                shards[i] = shards[i + 2];
            }
            length -= 2;

            if (length == 1)
            {
                return 'Y';
            }

            l = 0;
            r = l + 2;
        }
    }
    return 'N';
}
