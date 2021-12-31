#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "complex.h"

#define MAX_LINE 80   /* Maximum line length assumed to be 80. */
#define NUM_OF_FUNC 9 /* Number of functions in complex.c is 9. */

/* For code readability, names were assigned. */
enum operations { READ_COMP,
                  PRINT_COMP,
                  ADD_COMP,
                  SUB_COMP,
                  MULT_COMP_REAL,
                  MULT_COMP_IMG,
                  MULT_COMP_COMP,
                  ABS_COMP,
                  STOP };

/* This function is responsible for receiving a line from the user and inserting it into a character array. If EOF is received, the program is stopped. */
void get_line(char[]);

/* This function receives the line as an array of characters and analyzes it. If the line is correct, it executes it. Otherwise it prints an error message.*/
void check_line(char[]);

/* The function receives a pointer to the string, and an array of pointers to strings. It returns the number of the command that the pointer is pointing to 
as described in enum, if the command is valid, otherwise it returns -1. */
int find_command(char *, char *[]);

/* The function receives a pointer to a string, and returns a pointer to the first character that is not ' ' or \t. */
char *skip_spaces(char *);

/* The function receives a pointer to a character in the string, and checks if it's a comma. */
int is_comma(char *);

/* The function receives a pointer to a character in the string, and checks if it's a complex number (A-F). */
int is_complex(char *);

/* The function receives a character A-F and returns a pointer to the corresponding complex variable. */
complex *find_complex(char);

/* The function receives a pointer to a string and manipulates it such that there are no longer any spaces, tabs, newlines in the string. */
void delete_spaces(char *);

/* The function exits the program. */
void stop();

/* The function receives a pointer and checks if there's extra characters in the string which are not required. */
int is_extraneous(char *);

/* The function receives a pointer and checks if it points to a valid number, also takes into account that the number may be negative. */
int is_number(char *);

/* The function returns the amount of bytes required to skip the number it that the pointer points to. */
int skip_num(char *);

/* The function checks if the pointer it receives is pointing at a parameter or if it's missing. */
int is_missing_param(char *);