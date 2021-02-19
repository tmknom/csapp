#include <stdio.h>
#include <limits.h>
#include "binary.h"

int tmult_ok(int x, int y) {
    int p = x * y;
    return !x || p / x == y;
}

int tmult32_ok(int32_t x, int32_t y) {
    int64_t p = (int64_t) x * (int64_t) y;

    printf("\n");
    printf("x:       ");
    print_binary_signed_integer(x);
    printf("y:       ");
    print_binary_signed_integer(y);
    printf("p:       ");
    print_binary_signed_long(p);
    printf("p >> 32: ");
    print_binary_signed_integer(p >> 31);

    // 結果がゼロの場合
    if (x == 0 || y == 0) {
        return 1;
    }

    // 結果が正の数の場合
    if ((x > 0 && y > 0) || (x < 0 && y < 0)) {
        return (p >> 31) == 0;
    }

    // 結果が負の数の場合
    return (p >> 31) == -1;
}

int tmult32_ok_answer(int32_t x, int32_t y) {
    int64_t p = (int64_t) x * (int64_t) y;
    return p == (int32_t) p;
}

void test_2_35() {
    printf("tmult_ok(1, 5)       = %d\n", tmult_ok(1, 5));
    printf("tmult_ok(-1, -5)     = %d\n", tmult_ok(-1, -5));
    printf("tmult_ok(INT_MAX, 2) = %d\n", tmult_ok(INT_MAX, 2));
    printf("tmult_ok(INT_MIN, 2) = %d\n", tmult_ok(INT_MIN, 2));
}

void test_2_36() {
    printf("tmult32_ok(1, 5)       = %d\n", tmult32_ok_answer(1, 5));
    printf("tmult32_ok(-1, -5)     = %d\n", tmult32_ok_answer(-1, -5));
    printf("tmult32_ok(INT_MAX, 2) = %d\n", tmult32_ok_answer(INT_MAX, 2));
    printf("tmult32_ok(INT_MAX, 1) = %d\n", tmult32_ok_answer(INT_MAX, 1));
    printf("tmult32_ok(INT_MIN, 2) = %d\n", tmult32_ok_answer(INT_MIN, 2));
    printf("tmult32_ok(INT_MIN, 1) = %d\n", tmult32_ok_answer(INT_MIN, 1));
}

int main() {
//    test_2_35();
    test_2_36();

    return 0;
}
