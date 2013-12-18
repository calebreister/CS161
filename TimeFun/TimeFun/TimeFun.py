#!/usr/bin/env python3.3

##PROGRAM: TimeFun
##AUTHOR: Caleb Reister
##DATE: 2013-11-18
##DEV ENV: MS Visual Studio 2013
##DESCRIPTION: This program will...
##	- Get the time in the 24hr format
##	- Convert that time to 12hr format
##	- Print the time in both the 24 and 12hr format
##NOTE: Python does not have pass-by-reference functions, but it
##  is able to return multiple values using the return() statement

def main():
    while True:
        print()
        hour24, minute = GetTime24()
        hour12, suffix = ConvertTime24to12(hour24)
        print("That time in the 12hr format is: ", end = '')
        PrintTime12(hour12, minute, suffix)
        print("That time in the 24hr format is: ", end = '')
        PrintTime24(hour24, minute)
        if AskRepeat() is False:# "is" is a valid comparison operator in Python, called the identity operator
            #"is" does the same as "=="
            break

##FUNCTION: GetTime24
##DESCRIPTION: Prompts the user for a time in the 24hr format
##PARAMETERS:
##	- (O) hour - the hours that the user entered
##	- (O) minute - the minutes that the user entered
##RETURN VALUES: none
def GetTime24():
    #this loop is a bit of a mess...
    #   - Python does not have a do...while statement
    #   - Python does not use an IO stream for input, so I needed to include some extra string-handling code
    #   - Because of these differences, it has become necessary to use break and continue statements
    while True:
        print("Enter a time using the 24 hour format (like 13:32): ", end = '')
        uInput = input()#input() returns a string
        if uInput.find(':') == -1:
            print("Make sure you separated the hours and minutes with a ':'.")
            continue
        uInput = uInput.split(':')#split separates the hour and minute values and makes them a list at the ':'
        #NOTE: python is not type-safe, you can change the type of any variable, I just turned a string into an array
        try:
            #if the user entered something other than an int, this try statement will fail, and it will follow the instructions
            #under except - probably because Python is interpreted
            hour = int(uInput[0])#[0] is the index number for the 1st list item
            minute = int(uInput[1])
        except:
            print("Please only enter integers for the hour and minute.")
            continue
        if hour < 0 or hour > 23:
            print("Please enter an hour between 0 and 23.")
        elif minute < 0 or minute > 59:
            print("Please enter the minute between 0 and 59.")
        else:
            break
    return(hour, minute)

##FUNCTION: ConvertTime24to12
##DESCRIPTION: converts the 24 hour time given to 12 hour time
##PARAMETERS:
##	- (I/O) hour
##	    in as an int between 0 and 23
##	    out converted to int between 0 and 12 with a suffix of A or P
##RETURN VALUES: the A (for AM) or P (for PM) suffix
def ConvertTime24to12(InHour):
    if InHour > 12:
        OutHour = InHour - 12
        return(OutHour, 'PM')
    elif InHour == 12:
        return(InHour, 'PM')
    elif InHour == 0:
        OutHour = 12
        return(OutHour, 'AM')
    else:
        return(InHour, 'AM')

##FUNCTION: PrintTime24
##DESCRIPTION: prints the time in the 24 hour format
##PARAMETERS:
##	- (I) hour - the hours field
##	- (I) minute - the minutes field
##RETURN VALUES: none, prints a value
def PrintTime24(hour, minute):
    print(round(hour, 2),':' , round(minute, 2))

##FUNCTION: PrintTime12
##DESCRIPTION: prints time in 12 hour format
##PARAMETERS:
##	- (I) hour - the hours field
##	- (I) minute - the minutes field
##RETURN VALUES: none, output printed
def PrintTime12(hour, minute, suffix):
    print(round(hour, 2), ':', round(minute, 2), suffix)

def AskRepeat():
    uInput = input("Do you want to run this program again? [Y/N] ")
    if uInput == 'y' or uInput == 'Y':
        return True
    else:
        return False

main()

##TEST DATA:
##"ab:cd" - puts stream in fail state (invalid type), reprompt
##"12 32" - pust stream in fail state (tries to write a 3 to char), reprompt
##"12-32" - reprompt
##"0:-12" - reprompt
##"0:81" - reprompt
##"-4:83" - reprompt
##"24:00" - commonly used but improper, reprompt
##"0:00" - output should be 12:00AM and 00:00
##"8:23" - output should be 8:23AM and 8:23
##"23:9" or "23:09" - output should be 11:09PM and 23:09
##"12:00" - output should be 12:00PM and 12:00
