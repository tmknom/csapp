#include <stdio.h>
#include <string.h>
#include "binary.h"

void int_to_short() {
    int x = 53191;
    short sx = (short) x;
    int y = sx;
    printf("int x = 53191:       ");
    print_binary_signed_integer(x);
    printf("short sx = (short)x: ");
    print_binary_signed_short(sx);
    printf("int y = sx:          ");
    print_binary_signed_integer(y);
}

void unsigned_minus() {
    unsigned length = 0;
    printf("unsigned length = 0; length - 1 = ");
    print_binary_unsigned_integer(length - 1);
}

float sum_elements(float a[], unsigned length) {
    int i;
    float result = 0;

    for (i = 0; i < length; i++) {
        result += a[i];
    }
    return result;
}

int strlonger(char *s, char *t) {
    return strlen(s) > strlen(t);
}

void test_2_26() {
    printf("('foobar' - 'foo' > 0): %d\n", strlonger("foobar", "foo"));
    printf("('foo' - 'foobar' > 0): %d\n", strlonger("foo", "foobar"));
}

int main() {
    int_to_short();
    printf("\n");
    unsigned_minus();
    printf("\n");

    float a[0] = {};
    float result = sum_elements(a, 0);
    printf("sum_elements = %f\n", result);

    printf("\n");
    test_2_26();

    return 0;
}
