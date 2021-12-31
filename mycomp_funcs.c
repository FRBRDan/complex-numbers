#include "mycomp.h"

extern complex A, B, C, D, E, F;

int find_command(char *p, char *commands[]) {
    int i = 0, count = 0;
    for (; !isspace(p[i]) && p[i] != ',' && p[i] != '\0'; i++) /* Counts length of string (until it reaches a space char, ',' or '\0'). */
        count++;

    for (i = 0; i < NUM_OF_FUNC; i++) {
        if (count == strlen(commands[i]) && !strncmp(p, commands[i], count)) /* Ensures that the strings are compared entirely. */
            return i;
    }
    return -1;
}

complex *find_complex(char c) {
    if (c == 'A')
        return &A;
    if (c == 'B')
        return &B;
    if (c == 'C')
        return &C;
    if (c == 'D')
        return &D;
    if (c == 'E')
        return &E;
    else
        return &F;
}

void stop() {
    printf("Thank you for using this program.\n");
    exit(0);
}

char *skip_spaces(char *p) {
    while (*p == ' ' || *p == '\t')
        p++;
    return p;
}

int is_comma(char *p) {
    return (*p == ',');
}

int is_complex(char *p) {
    return (*p >= 'A' && *p <= 'F');
}
int is_extraneous(char *p) {
    if (*p) { /* Ideally *p should point at '\0'. */
        printf("Error: Extraneous text after end of command.\n");
        return 1;
    }
    return 0;
}

void delete_spaces(char *p) {
    int i = 0, count = 0;
    while (p[i]) {
        if (!isspace(p[i]))
            p[count++] = p[i];
        i++;
    }
    p[count] = '\0'; /* End the string. */
}

int is_number(char *p) {
    return (isdigit(*p) || (*p == '-' && isdigit(p[1])));
}

int is_missing_param(char *p) {
    if (!*p) {
        printf("Error: Missing parameter.\n");
        return 1;
    }
    return 0;
}

int skip_num(char *p) {
    int i = 0;
    if (*p == '-') /* If negative number */
        i++;

    while (isdigit(p[i]))
        i++;

    if (p[i] == '.') /* If float number */
        while (isdigit(p[++i]))
            ;
    return i;
}