#include <stdio.h>
#include <limits.h>
#include "binary.h"

int uadd_ok(unsigned x, unsigned y) {
    unsigned result = x + y;
    return result >= x;
}

int main() {
    printf("uadd_ok(1, 3)        = %d\n", uadd_ok(1, 5));
    printf("uadd_ok(UINT_MAX, 0) = %d\n", uadd_ok(UINT_MAX, 0));
    printf("uadd_ok(UINT_MAX, 1) = %d\n", uadd_ok(UINT_MAX, 1));
    printf("uadd_ok(UINT_MAX, 5) = %d\n", uadd_ok(UINT_MAX, 5));

    return 0;
}
