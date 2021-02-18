#include <stdio.h>
#include "binary.h"

int func1(unsigned word) {
    return (int) ((word << 24) >> 24);
}

int func2(unsigned word) {
    return ((int) word << 24) >> 24;
}

void test_2_23_word(unsigned word) {
    printf("word: \n");
    print_binary_unsigned_integer(word);
    printf("(word << 24): \n");
    print_binary_unsigned_integer((word << 24));
    printf("(int) ((word << 24) >> 24): \n");
    print_binary_unsigned_integer((int) ((word << 24) >> 24));
    printf("((int) word << 24) >> 24: \n");
    print_binary_unsigned_integer(((int) word << 24) >> 24);
    printf("\n");
}


void test_2_23() {
    test_2_23_word(0x00000076);
    test_2_23_word(0x87654321);
    test_2_23_word(0x000000C9);
    test_2_23_word(0xEDCBA987);
}

int main() {
    test_2_23();

    return 0;
}
