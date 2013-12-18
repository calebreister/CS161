#!/usr/bin/env python3.3

##################################################
##Program: DataFun
##Author: Caleb Reister
##Date: 10/27/2013
##Dev Env: Visual Studio 2012
##Description: This program was assigned for learning about selection
##	structures based on user input.
##	"This program will allow you to demonstrate your mastery of ifs,
##	elses, and switch statements. It will consist of three parts, one
##	that deals with integers, one that deals with characters, and one
##	that deals with floating point numbers."
##################################################
#Declare input variables
print("Values of the wrong type will be changed...")
FavInt = int(input("What is your favorite integer less than 4 billion? "))
FavChar = str(input("What is your favorite printable character? "))#figure out char math in python
FavFloat = float(input("What is your favorite demial number? "))

##################################################
#calc and print int information
print("\n", "The integer ", FavInt, " is...")
#positive or negative
if FavInt >= 0:
    print("\t- positive")
else:
    print("\t- negative")
    
#greater than 10, 100, or 1000?
if FavInt > 1000:
    print("\t- greater than 1000")
elif FavInt > 100:
    print("\t- greater than 100")
else:
    print("\t- less than 10")
    
#odd or even?
if FavInt % 2 != 0:
    print("\t- an odd number")
else:
    print("\t- an even number")

#a noble gas?
if FavInt == 2:
    print("\t- the atomic number of helium (He)")
elif FavInt == 10:
    print("\t- the atomic number of neon (Ne)")
elif FavInt == 18:
    print("\t- the atomic number of argon (Ar)")
elif FavInt == 36:
    print("\t- the atomic number of krypton (Kr)")
elif FavInt == 54:
    print("\t- the atmoic number of xenon (Xe)")
elif FavInt == 86:
    print("\t- the atomic number of radon (Rn)")
else:
    print("\t- NOT the atomic number of a noble gas")

##################################################
print("\n")
print("The character '", FavChar, "' is...")
print("\t- UTF-8 value ", ord(FavChar))#get UTF-8 value, same as ASCII value
if FavChar >= '0' and FavChar <= '9':#is it a digit?
    print("\t- a digit")
elif FavChar >= 'A' and FavChar <= 'Z':#is it uppercase?
    print("\t- an UPPERCASE letter")
    if FavChar == 'A' or FavChar == 'E' or FavChar == 'I' or FavChar == 'O' or FavChar == 'U' or FavChar == 'Y':
        print("\t- a vowel")
    else:
        print("\t- NOT a vowel")
    LetterIndex = (ord(FavChar) - ord('A') + 1)
    LetterIndexMod = LetterIndex % 10
    if LetterIndexMod == 1:#index the letters
        if LetterIndex == 11:
            print("\t- the", LetterIndex, "th letter")
        else:
            print("\t- the", LetterIndex, "st letter")
    elif LetterIndexMod == 2:
        if LetterIndex == 12:
            print("\t- the", LetterIndex, "th letter")
        else:
            print("\t- the", LetterIndex, "nd letter")
    elif LetterIndexMod == 3:
        if LetterIndex == 13:
            print("\t- the", LetterIndex, "th letter")
        else:
            print("\t- the", LetterIndex, "rd letter")
    else:
        print("\t- the", LetterIndex, "the letter")
elif FavChar >= 'a' and FavChar <= 'z':#is it lowercase?
    print("\t- an lowercase letter")
    if FavChar == 'a' or FavChar == 'e' or FavChar == 'i' or FavChar == 'o' or FavChar == 'u' or FavChar == 'y':
        print("\t- a vowel")
    else:
        print("\t- NOT a vowel")
    LetterIndex = (ord(FavChar) - ord('a') + 1)
    LetterIndexMod = LetterIndex % 10
    if LetterIndexMod == 1:#index the letters
        if LetterIndex == 11:
            print("\t- the", LetterIndex, "th letter")
        else:
            print("\t- the", LetterIndex, "st letter")
    elif LetterIndexMod == 2:
        if LetterIndex == 12:
            print("\t- the", LetterIndex, "th letter")
        else:
            print("\t- the", LetterIndex, "nd letter")
    elif LetterIndexMod == 3:
        if LetterIndex == 13:
            print("\t- the", LetterIndex, "th letter")
        else:
            print("\t- the", LetterIndex, "rd letter")
    else:
        print("\t- the", LetterIndex, "the letter")
else:
    print("\t- a special character")

##################################################
print("\n")
FavFloatLeft = int(FavFloat)#isolate sides of decimal
FavFloatRight = FavFloat - FavFloatLeft
print("The decimal number ", FavFloat, "...")
if FavFloatRight == 0:
    print("\t- CAN be stored as an integer.")#can it be stored as an int?
else:
    print("\t- CANNOT be stored as an integer.")
print("\t- Value left of decimal: ", FavFloatLeft)
print("\t- Value right of decimal: ", FavFloatRight)
