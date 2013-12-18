/*========================================
Program: GeometryFun2
Author: Caleb Reister
Date: 10/19-21/2013
Dev Env: Visual Studio 2012
Description:
	Second version of GeometryFun:
	+ Equilateral triangle calculations
	+ Determines if input was too large correctly
	+ Improved code readability (cout statements are now written
		like they will show in the console)
	+ Improved program logic (removed meaningless if statement)
========================================*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const float PI = 3.14159f;

void main(){
	unsigned long input;
	//square variables
	unsigned long long SqPerimeter;
	unsigned long long SqArea;
	//circle variables
	double radius;
	double circumference;
	long double cArea;
	bool loop = 1;//variable used by while loop for error detection
	//equilateral triangle variables
	long double tPerimeter;
	long double tArea;

//Get user input: prompt for positive whole number
cout << "Enter a positive whole number: ";
cin >> input;
cout << endl;

while(loop == 1)//repeat if too large of a value is entered
	if(input <= 1000000000){
		//calculate square properties
		SqPerimeter = input *4;
		SqArea = pow(input,2);
		//print square properties
		cout << "Square side length: " << input << endl
			<< "\tPerimeter: " << SqPerimeter << endl
			<< "\tArea: " << SqArea << endl;

		//compute circle properties
		radius = static_cast<long double>(input) / 2;
		circumference = static_cast<long double>(input) * PI;
		cArea = static_cast<long double>(pow(input,2)) * PI;
		//print circle properties
		cout << setprecision(3)
			<< "Circle diameter: " << input << endl
			<< "\tRadius: " << radius << endl
			<< "\tCircumference: " << circumference << endl
			<< "\tArea: " << cArea << endl;

		//compute equilateral tringle properties
		tPerimeter = input * 3;
		tArea = ( pow(input,2) * sqrt(3) ) / 4;
		//print triangle properties
		cout << setprecision(3)
			<< "Equilateral triangle side length: " << input << endl
			<< "\tPerimeter: " << tPerimeter << endl
			<< "\tArea: " << tArea << endl;

		//keep console window open when ran in GUI
		cin.ignore(numeric_limits<streamsize>::max(),'\n');//ignore all input until \n
		cin.get();
		break;//exit the loop
	}
	else {
		cin.clear();//clear cin so that extra bits don't go into input
		cout << "The number you entered was too big. Please enter a lower number." << endl;
		//prompt for user input
		cout << "Enter a positive whole number: ";
		cin >> input;
		cout << endl;
	}
}