// My first program. WooHoo!!
#include <iostream>//references external file that contains info for library
// <> looks in default system path for header file
// # is a "preprocessor directive" preprocessor runs before code is compiled
// in this case it replaces the iostream line with the contents of iostream

using namespace std;// standard namespace
//namespace: allows for libraries to use commands with the same name but in different libraries
//namespace for iostream is std

void main(){// main() is required in any C, C++, or Java program
	int x;
	x = 4 + 6;//whitespace can make lines easier to read, x = 4 + 6 could be x=4+6
	std::cout << "this was my first program";// :: specifies a namespace - not required in this case
	// "string" is a string literal, it tells the code to use the EXACT text you entered
	cin.get();//the enter key exits, this is also a part of iostream
	//examples from the book don't use std::
	//rather then typing in std:: every time, you put using namespace std; at the top... it will then use std ad default and you have to specify any other namespace
}