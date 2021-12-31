#include <math.h>
#include <stdio.h>

/* complex number struct */
typedef struct {
    double real;
    double imaginary;
} complex;

/* The function inserts a value into a complex variable. */
void read_comp(complex *x, double real, double imaginary);

/* The function prints the valud of a complex number. */
void print_comp(complex *x);

/* The function receives two complex numbers, adds their values and prints the result. */
void add_comp(complex *x, complex *y);

/* The function receives two complex numbers, subtracts their values and prints the result. */
void sub_comp(complex *x, complex *y);

/* The function receives a complex number and a real number, multiplies them and prints the result. */
void mult_comp_real(complex *x, double number);

/* The function receives a complex number and an imaginary number, multiplies them and prints the result. */
void mult_comp_img(complex *x, double imaginary);

/* The function receives two complex numbers, multiplies their values and prints the result. */
void mult_comp_comp(complex *x, complex *y);

/* The function receives a complex number and prints its absolute value. */
void abs_comp(complex *x);