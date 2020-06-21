#include <iostream>
#include <bitset>

using namespace std;

int main() {
	cout << "Enter a boolean value (0 or 1, meaning true or false, respectively): ";
	bitset<1> op1 = 0;
	cin >> op1;

	cout << "Enter another one: ";
	bitset<1> op2 = 0;
	cin >> op2;

	// bitwise NOT operator (unary)
	cout << "~" << op1 << " = " << ~op1 << endl;
	
	// bitwise AND operator
	cout << op1 << " & " << op2 << " = " << (op1 & op2) << endl;
	
	// bitwise OR operator
	cout << op1 << " | " << op2 << " = " << (op1 | op2) << endl;
	
	// bitwise XOR operator
	cout << op1 << " ^ " << op2 << " = " << (op1 ^ op2) << endl;

	return 0;
}
