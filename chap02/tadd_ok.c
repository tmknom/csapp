#include <stdio.h>
#include <limits.h>
#include "binary.h"

int tadd_ok(int x, int y) {
    int sum = x + y;
    if (x > 0 && y > 0 && sum <= 0) {
        return 0;
    }
    if (x < 0 && y < 0 && sum >= 0) {
        return 0;
    }
    return 1;
}

int buggy_tadd_ok(int x, int y) {
    int sum = x + y;
    printf("buggy_tadd_ok: x = %d, y = %d, sum = %d, sum - x = %d, sum - y = %d\n", x, y, sum, sum - x, sum - y);
    printf("x:       ");
    print_binary_signed_integer(x);
    printf("y:       ");
    print_binary_signed_integer(y);
    printf("sum:     ");
    print_binary_signed_integer(sum);
    printf("sum - x: ");
    print_binary_signed_integer(sum - x);
    printf("sum - y: ");
    print_binary_signed_integer(sum - y);
    return (sum - x == y) && (sum - y == x);
}

int tadd_ok_detail(int x, int y) {
    int sum = x + y;
    printf("tadd_ok_detail: x = %d, y = %d, sum = %d, sum - x = %d, sum - y = %d\n", x, y, sum, sum - x, sum - y);
    printf("x:       ");
    print_binary_signed_integer(x);
    printf("y:       ");
    print_binary_signed_integer(y);
    printf("sum:     ");
    print_binary_signed_integer(sum);
    printf("sum - x: ");
    print_binary_signed_integer(sum - x);
    printf("sum - y: ");
    print_binary_signed_integer(sum - y);
    if (x > 0 && y > 0 && sum <= 0) {
        return 0;
    }
    if (x < 0 && y < 0 && sum >= 0) {
        return 0;
    }
    return 1;
}

int tsub_ok(int x, int y) {
    printf("\ntsub_ok: x = %d, y = %d\n", x, y);
    return tadd_ok_detail(x, -y);
}

void test_2_30() {
    printf("tadd_ok(1, 5)        = %d\n", tadd_ok(1, 5));
    printf("tadd_ok(-1, -5)      = %d\n", tadd_ok(-1, -5));
    printf("tadd_ok(INT_MAX, 0)  = %d\n", tadd_ok(INT_MAX, 0));
    printf("tadd_ok(INT_MAX, 1)  = %d\n", tadd_ok(INT_MAX, 1));
    printf("tadd_ok(INT_MIN, 0)  = %d\n", tadd_ok(INT_MIN, 0));
    printf("tadd_ok(INT_MIN, -1) = %d\n", tadd_ok(INT_MIN, -1));
}

void test_2_31() {
    printf("\n");
    printf("buggy_tadd_ok(INT_MAX, 1)  = %d\n", buggy_tadd_ok(INT_MAX, 1));
}

void test_2_32() {
    printf("\n");
    printf("tsub_ok(INT_MIN, INT_MIN) = %d\n", tsub_ok(INT_MIN, INT_MIN));
    printf("tsub_ok(INT_MAX, INT_MIN) = %d\n", tsub_ok(INT_MAX, INT_MIN));
    printf("tsub_ok(INT_MIN, INT_MIN+1) = %d\n", tsub_ok(INT_MIN, INT_MIN + 1));
    printf("tsub_ok(INT_MAX, INT_MIN+1) = %d\n", tsub_ok(INT_MAX, INT_MIN + 1));
}

int main() {
    test_2_30();
    test_2_31();
    test_2_32();

    return 0;
}
