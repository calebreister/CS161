#!/usr/bin/env python3.3

##/*================================================
##Program: LoopFun
##Author: Caleb Reister
##Date: 10/31-11/4/2013
##Dev Env: Visual Studio 2012
##Description: Loop Practice
##	- Get two int values from user for width and height
##	- Check to make sure values entered are in valid range
##	- Print numbers between width and height
##	- Create a rectangle outline out of '*' with a width and height
##		corrosponding to the numbers entered
##	- Create a triangle from '*' with a height corrosponding to the user input
##		- The width at the tip has two '*' and each layer below adds 2 '*'
##=================================================*/

print("ENTER POSITIVE WHOLE NUMBERS ONLY...")
height = int(input("Please enter the height of a rectangle (between 3 and 10): "))#get height
print("Please enter the width of a rectangle (between ", height, " and 20): ", end = '')#prompt width
#NOTE: Python automatically inserts a '\n' at the end of a print statement, end = '' or end = None removes this
#   you can put any character in place of that
width = int(input())#the prompt is an argument of input, but it is not mandatory

##################################################

#check input for errors
while width < height or height > 10 or width > 20:#NOTE: a<b<c evaluates from left to right in python
    if height < 3 or height > 10:
        print("The height you entered is out of range, try again: ", end = '')
        height = int(input())
    if width < height or width > 20:
        print("The width you entered is out of range, try again: ", end = '')
        width = int(input())
print()#prints a \n

##################################################

#show intermediate values between width and height
BoxDiff = height
print("Intermediate values:")
while BoxDiff <= width:
    print(BoxDiff, end = ' ')
    BoxDiff = BoxDiff + 1
print('\n')

##################################################

#create rectangle
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
print('\n')

##################################################

#create triangle
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
