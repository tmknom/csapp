#include <stdio.h>
#include "binary.h"

void create_binary(int v, char *binary) {
    int i = 0;
    unsigned int mask = (int) 1 << (sizeof(v) * 8 - 1);
    do {
        char bit = mask & v ? '1' : '0';
        binary[i] = bit;
        i++;
    } while (mask >>= 1);
}

void print_binary(int v) {
    const unsigned int BINARY_SIZE = sizeof(int) * 8;
    char binary[BINARY_SIZE + 1];
    binary[BINARY_SIZE] = 0; // 終端文字を入れておく
    create_binary(v, binary);

    printf("binary = %s, hex = 0x%.8x, decimal = %d\n", binary, v, v);
}
