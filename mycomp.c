#include "mycomp.h"

complex A, B, C, D, E, F;

int main() {
    char input[MAX_LINE]; /* Array of characters to hold the input of each line. */
    int running = 1;
    while (running) {
        get_line(input);
        check_line(input);
    }
    return 0;
}

void get_line(char line[]) {
    char newline = ' ';
    printf("\nPlease enter your desired command:\n");
    if (!fgets(line, MAX_LINE, stdin)) {
        printf("\nError: You reached EOF before the 'stop' command.\n");
        exit(0);
    }

    if (line[strlen(line)] != '\n')
        newline = '\n';

    printf("The command you entered is: %s%c", line, newline);
}

void check_line(char line[]) {
    char *commands[NUM_OF_FUNC] = {"read_comp", "print_comp", "add_comp", "sub_comp", "mult_comp_real", "mult_comp_img", "mult_comp_comp", "abs_comp", "stop"}; /* For subsequent comparison. */
    char *p = line;
    int command;                  /* This will hold the number of the command entered by the user, in the order of the array and enum in mycomp.h. */
    char *first_num, *second_num; /* These will point to the first number and the second number, in the cases they exist. */

    p = skip_spaces(p);

    if (*p == '\n') { /* If this is true, then the line is empty and irrelevant. */
        return;
    }

    command = find_command(p, commands);
    if (command == -1) {
        printf("Error: Undefined command name.\n");
        return;
    }
    p += strlen(commands[command]);
    delete_spaces(p);

    /* At this point *p points at one character after the command, and there are no white spaces in the string. */
    if (command == STOP) {
        if (is_extraneous(p))
            return;
        stop();
    }	
		
    if (is_comma(p)) {
        printf("Error: Illegal comma.\n");
        return;
    }

    if (is_missing_param(p))
        return;

    if (!is_complex(p)) {
        printf("Error: Undefined complex variable.\n");
        return;
    }
    p++;

    /* At this point *p points at one character after the first parameter. */
    if (command == PRINT_COMP || command == ABS_COMP) {
        if (is_extraneous(p))
            return;
        switch (command) {
            case PRINT_COMP:
                print_comp(find_complex(p[-1]));
                break;
            case ABS_COMP:
                abs_comp(find_complex(p[-1]));
                break;
        }
        return;
    }

    /* All commands at this point require a comma. For sub/add/mult_comp_comp the second parameter must be a compex number. */
    if (!is_comma(p) && *p) {
        printf("Error: Missing comma.\n");
        return;
    }
    if (is_missing_param(p))
        return;
    p++;

    if (is_comma(p)) {
        printf("Error: Multiple consecutive commas.\n");
        return;
    }

    /* At this point *p points at the second parameter. */
    if (command == SUB_COMP || command == ADD_COMP || command == MULT_COMP_COMP) {
        if (!is_complex(p)) {
            printf("Error: Invalid parameter - not a complex number.\n");
            return;
        }
        if (is_extraneous(p + 1))
            return;
        switch (command) {
            case SUB_COMP:
                sub_comp(find_complex(p[-2]), find_complex(*p));
                break;
            case ADD_COMP:
                add_comp(find_complex(p[-2]), find_complex(*p));
                break;
            case MULT_COMP_COMP:
                mult_comp_comp(find_complex(p[-2]), find_complex(*p));
                break;
        }
        return;
    }

    /* All remaining commands require a number as the second parameter. */

    if (!is_number(p)) {
        printf("Error: Invalid parameter - not a number.\n");
        return;
    }

    first_num = p;
    p += skip_num(p);

    /* At this point, *p points right after the first number. */
    if (command == MULT_COMP_IMG || command == MULT_COMP_REAL) {
        if (is_extraneous(p))
            return;
        switch (command) {
            case MULT_COMP_IMG:
                mult_comp_img(find_complex(first_num[-2]), atof(first_num));
                break;
            case MULT_COMP_REAL:
                mult_comp_real(find_complex(first_num[-2]), atof(first_num));
                break;
        }
        return;
    }

    /* The command must be read_comp at this point. */
    if (!is_comma(p) && *p) {
        printf("Error: Missing comma.\n");
        return;
    }
    if (is_missing_param(p))
        return;
    second_num = ++p;

    if (!is_number(p)) {
        printf("Error: Invalid parameter - not a number.\n");
        return;
    }
    p += skip_num(p);
    if (is_extraneous(p))
        return;
    read_comp(find_complex(first_num[-2]), atof(first_num), atof(second_num));
    return;
}
