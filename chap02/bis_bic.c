#include <stdio.h>

int bis(int x, int m) {
    return x | m;
}

int bic(int x, int m) {
    return x & ~m;
}

int bool_or(int x, int y) {
    int result = bis(x, y);
    return result;
}

int bool_xor(int x, int y) {
    int result = bis(bic(x, y), bic(y, x));
    return result;
}

void show_mask() {
    int input = 0x09; // 1001
    int mask = 0x05;  // 0101
    printf("m: %.8x\n", mask);
    printf("~m: %.8x\n", ~mask); // 1010
    printf("bis: %.8x\n", bis(input, mask)); // => 1101(D=13)
    printf("bic: %.8x\n", bic(input, mask)); // => 1000(8)
    printf("\n");
}

void test_2_13() {
    int input = 0x09; // 1001
    int mask = 0x05;  // 0101
    printf("bool_or : %.8x\n", bool_or(input, mask)); // => 1101(D=13)
    printf("bool_xor: %.8x\n", bool_xor(input, mask)); // => 1100(C=12)
}

int main() {
    show_mask();
    test_2_13();

    return 0;
}
