/*
PROGRAM: FunctionFun
AUTHOR: Caleb Reister
DATE: 2013-11-11
DEV ENV: Visual Studio 2012 Pro
DESCRIPTION: Identical to LoopFun but is function-based
 */

#include <iostream>
#include <iomanip>

using namespace std;

int GetInt(int low, int high);
void RangeMean(int low, int high);
void box(int height, int width);
void triangle(int height);

int main()
{
	int height;
	int width;

	cout << "Enter a box height (between 3 and 10): ";
	height = GetInt(3, 10);
	cout << "Enter a box width (between " << height << " and 20): ";
	width = GetInt(height, 20);

	cout << endl << endl
		<< "Intermediate values between " << height << " and " << width << ":" << endl;
	RangeMean(height, width);
	cout << endl << endl << endl;

	box(width, height);
	cout << endl << endl;
	triangle(height);

	cin.get();
	cin.ignore();
}

int GetInt(int low, int high)
{
	/*
	FUNCTION: GetInt
	DESCRIPTION: uses cin to get an integer within a range

	ARGUMENT LIST:
		- low: the starting value of the range
		- high: the final value of the range
	
	RETURN VALUES:
		- input if the number is in range, loops until a valid value is entered otherwise
	*/
	int input;
	cin >> input;
	while (input < low || input > high)
	{
		if (input < low)
			cout << "The number you entered is too low, try again: ";
		else if (input > high)
			cout << "The number you entered is too high, try again: ";
		cin >> input;
	}
	return input;
}

void RangeMean(int low, int high)//show intermediate values between high and low, calculate average
{
	/*
	FUNCTION: RangeMean
	DESCRIPTION: prints the intermediate values and average of the arguments
	
	ARGUMENT LIST:
		- low: start of the range
		- high: end of the range
	
	RETURN VALUES: void
	*/
	for (int IntMed = low; IntMed <= high; IntMed++)//IntMed is the intermediate value to be printed
		cout << IntMed << " ";
	cout << endl << "Average: " << (low + high) / 2.0;
}

void box(int width, int height)
{
	/*
	FUNCTION: box
	DESCRIPTION: creates a box out of '*' with the set width and height
	ARGUMENT LIST:
		- width: the box width
		- height: the box height
	
	RETURN VALUES: void
	*/
	int horizontal;
	int vertical;
	for (horizontal = 1; horizontal <= width; horizontal++)//1st horizontal line
		cout << "* ";
	for (vertical = 2; vertical < height; vertical++)//vertical lines
		cout << setw((width - 1) * 2) << endl//set width of print to 2 * number of '*' to account for ' '
			//in horizontal lines, subtracted 1 to offset width so it doesn't create '*' past end of rectangle
			<< left << "*" << right << "*";
	cout << endl;
	for (horizontal = 1; horizontal <= width; horizontal++)//2nd horizontal line
		cout << "* ";
}

void triangle(int height)
{
	/*
	FUNCTION: triangle
	DESCRIPTION: prints a triangle starting with "**", adding "**" each row
	ARGUMENT LIST:
		- height: the number of rows to print
	RETURN VALUES: void
	*/
	int vertical;
	int horizontal = 4;
	cout << "* *";//triangle always starts with * *
	for (vertical = 1; vertical < height; vertical++)//vertical position of curosr
	{
		cout << endl;
		for (int start = 1; start <= horizontal; start++)//content for each line
			//start defines starting point of * creation keeps adding "* " until horizontal is reached
			cout << "* ";
		horizontal += 2;// add to number of '* ' to create after each line, +=2 was assigned
	}
}