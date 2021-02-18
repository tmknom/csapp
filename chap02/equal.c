#include <stdio.h>

int equal(int x, int y) {
    return !((x & ~y) | (~x & y));
}

void test_2_15() {
    printf("equal(5, 5)  : %d\n", equal(5, 5));
    printf("equal(3, 5)  : %d\n", equal(3, 5));
    printf("equal(-5, -5): %d\n", equal(-5, -5));
    printf("equal(5, -5) : %d\n", equal(5, -5));
}

int main() {
    test_2_15();

    return 0;
}
