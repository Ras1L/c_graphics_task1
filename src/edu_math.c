#include "edu_math.h"

#include <stdio.h>
#include <stdlib.h>

#define UNIMPLEMENTED \
    do { \
        fprintf(stderr, "[ERROR] function %s is unimplemented\n", __func__); \
        abort(); \
    } while (0)

#define UNUSED(x) (void)(x)

int edu_add(int a, int b) {
    return a + b;
}

int edu_sub(int a, int b) {
    return a - b;
}

int edu_mult(int a, int b) {
    return a * b;
}

int edu_div(int a, int b) {
    return a / b;
}

int edu_mod(int a, int b) {
    return a % b;
}

int edu_pow(int a, int b) {
    if (b == 0) { return 1; }
    int tmp = a;
    for (int i = 1; i < b; ++i)
    {
        a *= tmp;
    }
    return a;
}

int edu_abs(int a) {
    if (a >= 0){
        return a;
    }
    else {
        return ~a + 1;
    }
}

int edu_gcd(int a, int b) {
    if (a > b) {
        while (b != 0){
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
    else if (a < b) {
        while (a != 0){
            int tmp = a;
            a = b % a;
            b = tmp;
        }
        return b;
    }
    else { return a; }
}

int edu_lcm(int a, int b) {
    if (a == 0 || b == 0) { return 0; }
    return (a / edu_gcd(a, b) * b);
}

int edu_int_sqrt(int a) {
    if (a == 0 || a == 1) { return a; }
    int x = a;
    int prev_x;
    do {
        prev_x = x;
        x = (x + a/x) / 2;
    } while (x < prev_x);
    return prev_x;
}

int edu_sgn(int a) {
         if (a < 0) { return -1;}
    else if (a > 0) { return 1; }
    else            { return 0; }
}

int edu_fact(int a) {
    if (a == 0 || a == 1) { return 1; }
    int res = 1;
    for (int i = 2; i <= a; ++i) {
        res *= i;
    }
    return res;
}
