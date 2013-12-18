/*========================================
Program: GeometryFun
Author: Caleb Reister
Date: 10/9/2013
Dev Env: Visual Studio 2010 Express
Description:
	Calculates and prints:
	- The perimeter and area of a square with a side length of input
	- The radius, circumference, and area or a circle with a diameter of input
========================================*/

#include <iostream>

using namespace std;

void main(){
	const float PI = 3.13416f;//MOVE ABOVE main(), COMMON PROCEDURE
	
	unsigned long input;
	//square variables
	unsigned long perimeter;
	unsigned long SqArea;//try long long
	//circle variables
	double radius;
	double circumference;
	long double cArea;
	
	//Get user input: prompt for positive whole number
	cout << "Enter a positive whole number <=4294967295: ";
	cin >> input;
	cout << endl;

	//Compute square properties
	cout << "Square side length: " << input << endl;
	/* THIS IF STATEMENT IS MEANINGLESS, THE COMPUTER STILL HAS TO STORE THE DATA,
		EVEN IF YOU DO NOT TELL IT TO STORE THE RESULT
	if (input * input < 4294967295){//make sure answer does not overload output
		//calculate
		perimeter = input *4;
		SqArea = input * input;
		//print
		cout << "\tPerimeter: " << perimeter << endl;
		cout << "\tArea: " << SqArea << endl;
	}
	else{
		//only allocates extra memory if necessary
		long double perimeterFloat = static_cast<long double>(input) * 4;
		long double SqAreaFloat = static_cast<long double>(input * input);
		//output
		cout << "\tPerimeter: " << perimeterFloat << endl;
		cout << "\tArea: " << SqAreaFloat;
		cout << "static_cast";
	}
	*/
	//compute circle properties
	radius = static_cast<long double>(input) / 2;
	circumference = static_cast<long double>(input) * PI;
	cArea = static_cast<long double>(input * input) * PI;
	//print circle properties
	cout << "Circle diameter: " << input << endl;
	cout << "\tRadius: " << radius << endl;
	cout << "\tCircumference: " << circumference << endl;
	cout << "\tArea: " << cArea;

	//keep console window open when ran in GUI
	cin.ignore();
	cin.get();
}