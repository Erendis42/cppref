#include <iostream>
using namespace std;

const float PI = 3.141592;

inline int Square(int inputNum) {
	return inputNum * inputNum;
}

void CalculateAreaAndCircumference() {
	unsigned int radius = 0;

	cout << "Enter a positive integer as the radius of the circle: " << endl;
	cin >> radius;

	float area{ Square(radius) * PI };
	float circumference{ 2 * radius * PI };

	cout << "The area of the circle is: " << area << endl \
		<< "The circumference of the circle is: " << circumference << endl;
}

int main() {	
	CalculateAreaAndCircumference();

	return 0;
} 
