#include <iostream>
using namespace std;

const float pi = 3.141592;

void CalculateAreaAndCircumference() {
	unsigned int radius = 0;

	cout << "Enter a positive integer as the radius of the circle: "
		<< endl;

	cin >> radius;

	float area{ radius * radius * pi };
	float circumference{ 2 * radius * pi };

	cout << "The area of the circle is: " << area << endl
		<< "The circumference of the circle is: " << circumference << endl;
}

int main() {	
	CalculateAreaAndCircumference();

	return 0;
} 
