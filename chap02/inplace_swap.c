#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt - 1; first <= last; first++, last--) {
        inplace_swap(&a[first], &a[last]);
    }
}

void reverse_array2(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt - 1; first < last; first++, last--) {
        inplace_swap(&a[first], &a[last]);
    }
}

void print_array(char *prefix, int a[], int cnt) {
    printf("%s: [", prefix);
    for (int i = 0; i < cnt; ++i) {
        printf("%d, ", a[i]);
    }
    printf("]\n");
}

void test_2_11() {
    int a[5] = {1, 2, 3, 4, 5};
    int size_a = sizeof(a) / sizeof(int);

    printf("reverse_array\n");
    print_array("input", a, size_a);
    reverse_array(a, size_a);
    print_array("output", a, size_a);

    int b[5] = {1, 2, 3, 4, 5};
    int size_b = sizeof(b) / sizeof(int);

    printf("\nreverse_array2\n");
    print_array("input", b, size_b);
    reverse_array2(a, size_b);
    print_array("output", b, size_b);
}

int main() {
    test_2_11();

    return 0;
}
