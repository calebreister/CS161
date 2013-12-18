/*================================================
Program: LoopFun
Author: Caleb Reister
Date: 10/31-11/4/2013
Dev Env: Visual Studio 2012
Description: Loop Practice
	- Get two int values from user for width and height
	- Check to make sure values entered are in valid range
	- Print numbers between width and height
	- Create a rectangle outline out of '*' with a width and height
		corrosponding to the numbers entered
	- Create a triangle from '*' with a height corrosponding to the user input
		- The width at the tip has two '*' and each layer below adds 2 '*'
=================================================*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int width;//user input
	int height;//user input
	int horizontal;//used in multiple loops (reset each time), declared here to
		//prevent the repeated creation and deletion of variables for the same purpose
	int vertical;//used in loops
	
	//=============================================

	//get width and height
	cout << "ENTER WHOLE NUMBERS ONLY..." << endl 
		<< "Please enter the height of a rectangle (between 3 and 10): ";
	cin >> height;
	cout << "Please enter the width of a rectangle (between " << height << " and 20): ";
	cin >> width;

	//=============================================

	//check input for errors
	//attempted to compensate for any random input, but did not work
	//could be possible if auto variable type were used
	while (width < height || width > 20 || height < 3)
	{
		cin.clear();//clear fail state in case the user entered an invalid type
		if (height < 3 || height > 10)//check height
		{
			cout << "The height you entered is out of range, try again: ";
			cin >> height;
		}
		if (width < height || width > 20)//check width
		{
			cout << "The width you entered is out of range, try again: ";
			cin >> width;
		}
	}

	//================================================
	
	cout << endl;

	//show intermediate values between width and height
	for (int BoxDiff = height; BoxDiff <= width; BoxDiff++)
	{
		//created BoxDiff can change without messing up the box values
		cout << BoxDiff << " ";
	}

	cout << endl << endl;

	//===================================================

	//create rectangle
	for (horizontal = 1; horizontal <= width; horizontal++)//1st horizontal line
	{
		cout << "* ";
	}
	for (vertical = 2; vertical <= (height - 1); vertical++)//vertical lines
	{
		cout << setw((width - 1) * 2) << endl//set width of print to 2 * number of '*' to account for ' '
			//in horizontal lines, subtracted 1 to offset width so it doesn't create '*' past end of rectangle
			<< left << "*" << right << "*";
	}
	cout << endl;
	for (horizontal = 1; horizontal <= width; horizontal++)//2nd horizontal line
	{
		cout << "* ";
	}

	cout << endl << endl;

	//===================================================

	//create triangle
	cout << "* *";//triangle always starts with * *
	horizontal = 4; //added 2 to number of * above
	for (vertical = 1; vertical <= (height - 1); vertical++)//vertical position of curosr
	{
		cout << endl;
		for (int start = 1; start <= horizontal; start++)//content for each line
			//start defines starting point of * creation keeps adding "* " until horizontal is reached
		{
			cout << "* ";
		}
		horizontal += 2;// add to number of '* ' to create after each line, +=2 was assigned
	}

	//=====================================================
	//keep console open
	cin.ignore();
	cin.get();
}