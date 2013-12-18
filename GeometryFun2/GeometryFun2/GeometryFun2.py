#Program: GeometryFun2
#Author: Caleb Reister
#Date: 10/19-21/2013
#Dev Env: Visual Studio 2012
#Description:
#	Second version of GeometryFun:
#	+ Equilateral triangle calculations
#	+ Determines if input was too large correctly
#	+ Improved code readability (cout statements are now written
#		like they will show in the console)
#	+ Improved program logic (removed meaningless if statement)

import math# #include equivalent
#Python has a math and cmath library like C++, but cmath will return a complex number
#   it can preform operations on negative roots without errors

#misc variables, types automatically assigned (Python is type safe)
PI = 3.14159#Python has no built-in constant system
uinput = 0#user input
loop = False
#square variables
SqPerimeter = 0
SqArea = 0
#circle variables
radius = 0
circumference = 0
cArea = 0
#triangle varirables
tPerimeter = 0
tArea = 0

##################################################
#get user input and check for errors
while loop == False:#true exits
    uinput = int(input("Enter a positive whole number: "))
    #Python's cin equivalent is input(), it comes in as a string, you have to use a type conversion (such as int())
    #   in order to use another type
    if uinput >= 1000000000:#Python uses a : to denote any number of lines within a statement...
        #   meaning that it is sensitive to tabs, and will give a syntax error if not tabbed correctly
        print("The number you entered was too big. Please enter a lower number.")#print() closely resembles cout
        loop = False
    else:
        loop = True
#Python has a for loop, but it is intended to iterate over an array or string, to create a simple counter, use while

##################################################
#calculate square values
SqPerimeter = uinput * 4
SqArea = uinput * 2
#print square values
print("Square side length: ", uinput)
print("\tPerimeter: ", SqPerimeter)
print("\tArea: ", SqArea)

##################################################
#calculate circle values
radius = float(uinput / 2)
circumference = float(uinput * PI)
cArea = float(radius**2 * PI)
#print circle values
print("Circle diameter: ", uinput)
print("\tRadius: ", radius)
print("\tCircumference: ", round(circumference, 3))#round() is the equivalent of setprecision()
print("\tArea: ", round(cArea, 3))

##################################################
#calc triangle values
tPerimeter = uinput * 3
tArea = float((uinput**2 * math.sqrt(3)) / 4)#CHECK EQUATION
#print triangle values
print("Equilateral triangle side length: ", uinput)
print("\tPerimter: ", round(tPerimeter, 3))
print("\tArea: ", round(tArea, 3))
