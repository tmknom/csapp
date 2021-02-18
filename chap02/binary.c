#include <stdio.h>
#include <stdbool.h>
#include "binary.h"

void create_binary_long(long v, char *binary) {
    int i = 0;
    unsigned long mask = (long) 1 << (sizeof(v) * 8 - 1);
    do {
        char bit = mask & v ? '1' : '0';
        binary[i] = bit;
        i++;
    } while (mask >>= 1);
}

void print_binary_long(long v, bool unsigned_flag) {
    const unsigned int BINARY_SIZE = sizeof(long) * 8;
    char binary[BINARY_SIZE + 1];
    binary[BINARY_SIZE] = 0; // 終端文字を入れておく
    create_binary_long(v, binary);

    if (unsigned_flag) {
        printf("binary = %s, hex = 0x%.8lx, decimal = %lu, type = u_long\n", binary, v, (unsigned long) v);
    } else {
        printf("binary = %s, hex = 0x%.8lx, decimal = %ld, type = long\n", binary, v, v);
    }
}

void print_binary_signed_long(long v) {
    print_binary_long(v, false);
}

void print_binary_unsigned_long(unsigned long v) {
    print_binary_long(v, true);
}

void create_binary_integer(int v, char *binary) {
    int i = 0;
    unsigned int mask = (int) 1 << (sizeof(v) * 8 - 1);
    do {
        char bit = mask & v ? '1' : '0';
        binary[i] = bit;
        i++;
    } while (mask >>= 1);
}

void print_binary_integer(int v, bool unsigned_flag) {
    const unsigned int BINARY_SIZE = sizeof(int) * 8;
    char binary[BINARY_SIZE + 1];
    binary[BINARY_SIZE] = 0; // 終端文字を入れておく
    create_binary_integer(v, binary);

    if (unsigned_flag) {
        printf("binary = %s, hex = 0x%.8x, decimal = %u, type = u_int\n", binary, v, (unsigned int) v);
    } else {
        printf("binary = %s, hex = 0x%.8x, decimal = %d, type = int\n", binary, v, v);
    }
}

void print_binary_signed_integer(int v) {
    print_binary_integer(v, false);
}

void print_binary_unsigned_integer(unsigned int v) {
    print_binary_integer(v, true);
}

void create_binary_short(short v, char *binary) {
    int i = 0;
    unsigned int mask = (int) 1 << (sizeof(v) * 8 - 1);
    do {
        char bit = mask & v ? '1' : '0';
        binary[i] = bit;
        i++;
    } while (mask >>= 1);
}

void print_binary_short(short v, bool unsigned_flag) {
    const unsigned int BINARY_SIZE = sizeof(short) * 8;
    char binary[BINARY_SIZE + 1];
    binary[BINARY_SIZE] = 0; // 終端文字を入れておく
    create_binary_short(v, binary);

    if (unsigned_flag) {
        printf("binary = %s, hex = 0x%.8x, decimal = %u, type = u_short\n", binary, v, (unsigned short) v);
    } else {
        printf("binary = %s, hex = 0x%.8x, decimal = %d, type = short\n", binary, v, v);
    }
}

void print_binary_signed_short(short v) {
    print_binary_short(v, false);
}

void print_binary_unsigned_short(unsigned short v) {
    print_binary_short(v, true);
}


void create_binary_char(char v, char *binary) {
    int i = 0;
    unsigned int mask = (int) 1 << (sizeof(v) * 8 - 1);
    do {
        char bit = mask & v ? '1' : '0';
        binary[i] = bit;
        i++;
    } while (mask >>= 1);
}

void print_binary_char(char v, bool unsigned_flag) {
    const unsigned int BINARY_SIZE = sizeof(char) * 8;
    char binary[BINARY_SIZE + 1];
    binary[BINARY_SIZE] = 0; // 終端文字を入れておく
    create_binary_char(v, binary);

    if (unsigned_flag) {
        printf("binary = %s, hex = 0x%.8x, decimal = %u, type = u_char\n", binary, v, (unsigned char) v);
    } else {
        printf("binary = %s, hex = 0x%.8x, decimal = %d, type = char\n", binary, v, v);
    }
}

void print_binary_signed_char(char v) {
    print_binary_char(v, false);
}

void print_binary_unsigned_char(unsigned char v) {
    print_binary_char(v, true);
}
