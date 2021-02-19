#include <stdio.h>
#include <limits.h>
#include "binary.h"

int div16_bias(int x) {
    if (x >= 0) {
        return x >> 4;
    } else {
        return (x + (1 << 4) - 1) >> 4;
    }
}

int div16(int x) {
    printf("x: ");
    print_binary_signed_integer(x);
    printf("x >> 31: ");
    print_binary_signed_integer(x >> 31);
    printf("(x >> 31) & 0xF: ");
    print_binary_signed_integer((x >> 31) & 0xF);
    return (x + ((x >> 31) & 0xF)) >> 4;
}

void test_2_42() {
    printf("div16(33)  = %d\n\n", div16(33)); // => 2
    printf("div16(-33) = %d\n\n", div16(-33)); // => -2
}

int main() {
    test_2_42();

    return 0;
}
