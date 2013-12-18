#!/usr/bin/env python3.3

##PROGRAM: FunctionFun
##AUTHOR: Caleb Reister
##DATE: 2013-11-19
##DEV ENV: IDLE 3.3.3
##DESCRIPTION: Identical to LoopFun but is function-based

def main():#main is not run here, I created it so that I can declare functions below it
    #I made a single call to main at the end of the program, that is the only direct function call I made
    print("Enter a box height (between 3 and 10): ", end = '')
    height = GetInt(3,10)#<function> tells Python to look in the FFDef file
    print("Enter a box width (between ", height, " and 20): ", end = '')
    width = GetInt(height, 20)
    print('\n')#go down 2 lines
    RangeMean(height, width)
    print('\n')
    DrawBox(width, height)
    print('\n')
    DrawTriangle(height)

##################################################
#In Python, function definitions must be at the top, it is interpreted
#   potential workaround is to define functions in a separate file

##FUNCTION: GetInt
##DESCRIPTION: uses cin to get an integer within a range
##ARGUMENT LIST:
##        - low: the starting value of the range
##        - high: the final value of the range
##RETURN VALUES:
##        - input if the number is in range, loops until a valid value is entered otherwise
def GetInt(low, high):#def is the keyword for define
    UserInput = int(input())
    while UserInput < low or UserInput > high:
        if UserInput < low:
            print("The number you entered is too low, try again: ", end = '')
            UserInput = int(input(prompt))
        elif UserInput > high:
            print("The number you entered is too high, try again: ", end = '')
            UserInput = int(input(prompt))
    return UserInput

##################################################
##FUNCTION: RangeMean
##DESCRIPTION: prints the intermediate values and average of the arguments
##ARGUMENT LIST:
##        - low: start of the range
##        - high: end of the range
##RETURN VALUES: void
def RangeMean(low, high):#put "pass" right after : to make the interprester disregard the function
    #this is used for functions that are still in implementation
    IntMed = low
    while IntMed <= high:
        print(IntMed, end = ' ')#specific arguments can be called in python functions
        IntMed = IntMed + 1
    print()
    print("Average: ", (low + high) / 2.0)

##################################################
##FUNCTION: DrawBox
##DESCRIPTION: creates a box out of '*' with the set width and height
##ARGUMENT LIST:
##        - width: the box width
##        - height: the box height
##RETURN VALUES: void
def DrawBox(width, height):
    #IDLE does not render text correctly for box, in order for box to work use a fixed
    #   width font or run this from terminal
    horizontal = 1#it is impractical to include all of these variables at the beginning
    #   these were embedded in the for() loop in the C++ version
    vertical = 2
    while horizontal <= width:
        print("* ", end = '')
        horizontal = horizontal + 1#horizontal++ does not work in Python
    print()#prints '\n', the default end character
    while vertical <= (height - 1):
        horizontal = 1
        print('* ', end = '')#figure out how to justify
        print('*'.rjust((width - 1) * 2 - 1))
        vertical = vertical + 1
    horizontal = 1
    while horizontal <= width:
        print("* ", end = '')
        horizontal = horizontal + 1

##################################################
##FUNCTION: DrawTriangle
##DESCRIPTION: prints a triangle starting with "**", adding "**" each row
##ARGUMENT LIST:
##        - height: the number of rows to print
##RETURN VALUES: void
def DrawTriangle(height):
    print("* *", end = '')#triangle always starts with this
    horizontal = 4#added to to "* *"
    vertical = 2
    while vertical <= height:
        print()
        start = 1
        while start <= horizontal:#create contents for each line
            #start defines starting point of * creation
            print("* ", end = '')
            start = start + 1
        horizontal = horizontal + 2
        vertical = vertical + 1
    print()

main()#this calls the function main
