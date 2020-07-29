#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void ReadFile(ifstream& infile, int& numberOfIntegers, vector<string>& input);
void PrintFile(int numberOfIntegers, std::vector<std::string>& input);
void ProcessEntry(vector<string>& entry);
bool Possible(string& in, string& out, int from, int to, int& n);
bool Allowed(char i_out, char j_in);

int main() {
    string filename = ".\\input.txt";
    ifstream infile(filename);

    int numberOfIntegers = 0;
    vector<string> input;

    ReadFile(infile, numberOfIntegers, input);
    //PrintFile(numberOfIntegers, input);

    int counter = 0;
    for (int i = 0; i < input.size(); i+=3) {
        cout << "Case #" << ++counter << ":" << endl;
        vector<string> entry;
        entry.push_back(input[i]);
        entry.push_back(input[i+1]);
        entry.push_back(input[i+2]);
        ProcessEntry(entry);
    }


    infile.close();
}

void ProcessEntry(vector<string>& entry) {
    //vector<string> entry = { "10", "NYYYNNYYYY", "YYNYYNYYNY" };

    stringstream integerAsString(entry[0]);
    int n = 0;
    integerAsString >> n;

    vector<vector<char>> matrix(n, vector<char>(n, 'N'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = 'Y';
            }
        }
    }

    string in = entry[1];
    string out = entry[2];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (Possible(in, out, i, j, n)) {
                matrix[i][j] = 'Y';
            }
        }
    }



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

bool Possible(string& in, string& out, int from, int to, int& n) {
    if (from < to) {
        for (int i = from; i < to; i++) {
            if (!Allowed(out[i], in[i + 1])) {
                return false;
            }
        }
        return true;
    }
    else {
        for (int i = to; i < from; i++) {
            if (!Allowed(out[i + 1], in[i])) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Allowed(char i_out, char j_in) {
    return i_out == 'Y' && j_in == 'Y';
}

void PrintFile(int numberOfIntegers, vector<string>& input)
{
    cout << numberOfIntegers << endl;
    for (string l : input)
    {
        cout << l << endl;
    }
    cout << endl;
}

void ReadFile(ifstream& infile, int& numberOfIntegers, vector<string>& input)
{
    string line;
    if (infile.is_open()) {
        bool first = true;
        while (infile >> line)
        {
            if (!first) {
                input.push_back(line);
            }
            else
            {
                stringstream integerAsString(line);
                integerAsString >> numberOfIntegers;
                first = false;
            }
        }
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}
