#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

void test_2_5() {
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer) &val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);
    show_bytes(valp, sizeof(int));
    show_bytes(valp, sizeof(byte_pointer));
}

void test_2_7() {
    const char *s = "12345";
    show_bytes((byte_pointer) s, strlen(s) + 1);

    const char *ss = "abcdef";
    show_bytes((byte_pointer) ss, strlen(ss) + 1);
}

int main() {
    test_show_bytes(12345);
    test_2_5();
    test_2_7();

    return 0;
}
