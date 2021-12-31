<h1 align="center">Complex Numbers</h1>

## About
This is an interactive program that reads commands from the standard input and deals with arithmetic operations on complex numbers. The program doesn't assume that the input is correct with no errors. 

## Usage
1. Run `make`
2. Run `./mycomp`

## File structure
  - `complex.c` - Deals with all arithmetic operations on complex numbers and prints the result (when required).
  - `mycomp.c` - Main program, it deals with receiving the input from the user, and ensuring the input is correct.
  - `mycomp_funcs.c` - Contains helper functions to mycomp.c, which aid in assessing the input.
  - `complex.h` - Implementation of "complex" data type using typedef, and declaration of functions.
  - `mycomp.h` - Implementation of constants, enum values, etc.


## Commands

There are 6 variables of "complex" data type, that may be used to store complex numbers called A - F. All of them are initialized to 0+0i in the beginning. Spaces are allowed between each word, comma, numbers or variable. The following commands are the valid commands that may be used:

**read_comp A, num1, num2** - inserts num1 + (num2)i into A.

**print_comp B** - prints the current value of B in the above format.

**add_comp B, C** - adds the values of B and C and prints the result.

**sub_comp A, B** - subtracts the value of B from A and prints the result.

**mult_comp_real D, 45** - multiplies the value of D by the real number 45 and prints it.

**mult_comp_img F, 10** - multiplies F by the imaginary number of 10, so by 10i and prints the result.

**mult_comp_comp A, E** - multiplies two complex numbers, in this case A and E and prints the result.

**abs_comp E** - prints the absolute value of E.

**stop** - stops the program. If EOF is encountered before the 'stop' command, the error is printed.
