#include <stdio.h>
#include <limits.h>
#include "binary.h"

void print_long() {
    long x = 12345;
    long mx = -x;
    unsigned long y, my;

    print_binary_signed_long(x);
    print_binary_signed_long(mx);

    y = x;
    my = mx;
    print_binary_unsigned_long(y);
    print_binary_unsigned_long(my);
}

void print_integer() {
    int x = 12345;
    int mx = -x;
    unsigned int y, my;

    print_binary_signed_integer(x);
    print_binary_signed_integer(mx);

    y = x;
    my = mx;
    print_binary_unsigned_integer(y);
    print_binary_unsigned_integer(my);

    print_binary_signed_integer(INT_MAX);
    print_binary_signed_integer(INT_MIN);
}

void print_short() {
    short x = 12345;
    short mx = -x;
    unsigned short y, my;

    print_binary_signed_short(x);
    print_binary_signed_short(mx);

    y = x;
    my = mx;
    print_binary_unsigned_short(y);
    print_binary_unsigned_short(my);
}

void print_char() {
    char x = 'a';
    short mx = -x;
    unsigned short y, my;

    print_binary_signed_char(x);
    print_binary_signed_char(mx);

    y = x;
    my = mx;
    print_binary_unsigned_char(y);
    print_binary_unsigned_char(my);
}

int main() {
    print_char();
    printf("\n");
    print_short();
    printf("\n");
    print_integer();
    printf("\n");
    print_long();

    return 0;
}
