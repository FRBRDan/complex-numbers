#include "complex.h"

void read_comp(complex *x, double real, double imaginary) {
    x->real = real;
    x->imaginary = imaginary;
}

void print_comp(complex *x) {
    char operator= x->imaginary >= 0 ? '+' : '-';
    int sign = operator== '+' ? 1 : - 1;
    printf("%.2f %c (%.2f)i\n", x->real, operator, x->imaginary * sign);
}

void add_comp(complex *x, complex *y) {
    complex tmp_num = {x->real + y->real, x->imaginary + y->imaginary};
    print_comp(&tmp_num);
}

void sub_comp(complex *x, complex *y) {
    complex tmp_num = {x->real - y->real, x->imaginary - y->imaginary};
    print_comp(&tmp_num);
}

void mult_comp_real(complex *x, double number) {
    complex tmp_num = {x->real * number, x->imaginary * number};
    print_comp(&tmp_num);
}

void mult_comp_img(complex *x, double imaginary) {
    complex tmp_num = {x->imaginary * imaginary * (-1), x->real * imaginary};
    print_comp(&tmp_num);
}

void mult_comp_comp(complex *x, complex *y) {
    complex tmp_num;
    tmp_num.real = x->real * y->real - x->imaginary * y->imaginary;
    tmp_num.imaginary = x->real * y->imaginary + x->imaginary * y->real;
    print_comp(&tmp_num);
}

void abs_comp(complex *x) {
    double absolute_value = sqrt(pow(x->real, 2) + pow(x->imaginary, 2));
    printf("%.2f\n", absolute_value);
}