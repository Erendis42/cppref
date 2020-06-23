#include <iostream>
using namespace std;

const double Pi = 3.1416;

double Volume(double radius);
double Volume(double radius, double height);

int main()
{
	cout << "Enter radius: ";
	double radius = 0;
	cin >> radius;

	cout << "Do you want to calculate the volume of a cylinder or a sphere? (c/s) ";
	char userInput = 'c';
	cin >> userInput;

	if (userInput == 'c')
	{
		cout << "Enter the height of the cylinder: ";
		double height = 0;
		cin >> height;

		cout << "The volume of the cylinder is: " << Volume(radius, height) << endl;
	}
	else
		cout << "The volume of the sphere is: " << Volume(radius) << endl;
}

double Volume(double radius)
{
	return (4 * Pi * radius * radius * radius) / 3;
}

double Volume(double radius, double height)
{
	return Pi * radius * radius * height;
}
