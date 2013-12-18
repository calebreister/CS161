/*
PROGRAM: TimeFun
AUTHOR: Caleb Reister
DATE: 2013-11-18
DEV ENV: MS Visual Studio 2013
DESCRIPTION: This program will...
	- Get the time in the 24hr format
	- Convert that time to 12hr format
	- Print the time in both the 24 and 12hr format
 */

#include <iostream>
#include <iomanip>

void GetTime24(int& hour, int& minute);
char ConvertTime24to12(int InHour, int& OutHour);
void PrintTime24(int hour, int minute);
void PrintTime12(int hour, int minute, char suffix);
bool AskRepeat();


using namespace std;

int main()
{
	int hour24;
	int hour12;
	int minute;
	char suffix;
	do
	{
		GetTime24(hour24, minute);//get 24h time
		suffix = ConvertTime24to12(hour24, hour12);//convert to 12h time
		//print 12h time
		cout << "That time in the 12hr format is: ";
		PrintTime12(hour12, minute, suffix);
		//print 24h time
		cout << "That time in the 24hr format is: ";
		PrintTime24(hour24, minute);
		cout << endl;
	} while (AskRepeat());
}

/*========================================
FUNCTION: GetTime24
DESCRIPTION: Prompts the user for a time in the 24hr format
PARAMETERS:
	- (O) hour - the hours that the user entered
	- (O) minute - the minutes that the user entered
RETURN VALUES: none
*/
void GetTime24(int& hour, int& minute)
{
	bool loop = true;
	do
	{
		char delim;//used as the delimeter for the hours and minutes
		cout << "Enter a time using the 24 hour format: ";
		cin >> hour >> delim >> minute;
		//check validity of input
		if (!cin)//check cin for fail state
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');//ignore until end of steam (line ending in this case)
			cout << "ONLY INTEGERS, PLEASE" << endl;
		}
		else if (delim != ':')//check delimiter
			cout << "PLEASE SEPARATE THE HOURS WITH A ':'" << endl;
		else if (hour < 0 || hour > 23)//check hours
			cout << "PLEASE ENTER AN HOUR BETWEEN 0 AND 32" << endl;
		else if (minute < 0 || minute > 59)//check minutes
			cout << "PLEASE ENTER A MINUTE BETWEEN 0 and 59" << endl;
		else
			loop = false;
	} while (loop == true);
}

/*========================================
FUNCTION: ConvertTime24to12
DESCRIPTION: converts the 24 hour time given to 12 hour time
PARAMETERS:
	- (I/O) hour
		in as an int between 0 and 23
		out converted to int between 0 and 12 with a suffix of A or P
RETURN VALUES: the A (for AM) or P (for PM) suffix
*/
char ConvertTime24to12(int InHour, int& OutHour)
{
	if (InHour > 12)
	{
		OutHour = InHour - 12;
		return 'P';
	}
	else if (InHour == 12)
	{
		OutHour = InHour;
		return 'P';
	}
	else if (InHour == 0)
	{
		OutHour = 12;
		return 'A';
	}
	else
	{
		OutHour = InHour;
		return 'A';
	}
}

/*========================================
FUNCTION: PrintTime24
DESCRIPTION: prints the time in the 24 hour format
PARAMETERS:
	- (I) hour - the hours field
	- (I) minute - the minutes field
RETURN VALUES: none, prints a value
*/
void PrintTime24(int hour, int minute)
{
	cout << setw(2) << setfill('0') << hour
	<< ':' 
	<< setw(2) << setfill('0') << minute << endl;
}

/*========================================
FUNCTION: PrintTime12
DESCRIPTION: prints time in 12 hour format
PARAMETERS:
	- (I) hour - the hours field
	- (I) minute - the minutes field
RETURN VALUES: none, output printed
*/
void PrintTime12(int hour, int minute, char suffix)
{
	cout << setw(2) << setfill('0') << hour
		<< ':' 
		<< setw(2) << setfill('0') << minute
		<< suffix << 'M' << endl;
}

/*========================================
FUNCTION: AskRepeat
DESCRIPTION: asks the user if they want to repeat the program
PARAMETERS: none, gets user input directly
RETURN VALUES:
	- true if input is 'y' or 'Y'
	- false if input is anything else
*/
bool AskRepeat()
{
	char input;
	cout << "Do you want to run this program again? [Y/N] ";
	cin >> input;
	if (input == 'y' || input == 'Y')
		return true;
	else
		return false;
}

/*
TEST DATA:
"ab:cd" - puts stream in fail state (invalid type), reprompt
"12 32" - pust stream in fail state (tries to write a 3 to char), reprompt
"12-32" - reprompt
"0:-12" - reprompt
"0:81" - reprompt
"-4:83" - reprompt
"24:00" - commonly used but improper, reprompt
"0:00" - output should be 12:00AM and 00:00
"8:23" - output should be 8:23AM and 8:23
"23:9" or "23:09" - output should be 11:09PM and 23:09
"12:00" - output should be 12:00PM and 12:00
*/