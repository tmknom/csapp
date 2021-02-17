#include <stdio.h>

void show_mask() {
    printf("(int64_t) 0xFF  : %.16llx\n", (int64_t) 0xFF);
    printf("(int64_t)(~0xFF): %.16llx\n", (int64_t)(~0xFF));
    printf("(int32_t) 0xFF  : %.8x\n", (int32_t) 0xFF);
    printf("(int32_t)(~0xFF): %.8x\n", (int32_t)(~0xFF));
    printf("\n");
}

void test_2_12_a(int val) {
    int result = val & 0xFF;
    printf("result A: %.8x\n", result);
}

void test_2_12_b(int val) {
    int result = val ^~0xFF;
    printf("result B: %.8x\n", result);
}

void test_2_12_c(int val) {
    int result = val | 0xFF;
    printf("result C: %.8x\n", result);
}

void test_2_12() {
    int val = 0x87654321;
    printf("input   : %.8x\n", val);
    test_2_12_a(val);
    test_2_12_b(val);
    test_2_12_c(val);
}

int main() {
    show_mask();
    test_2_12();

    return 0;
}
