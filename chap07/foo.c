#include <stdio.h>

void f(void);

int x = 123;
int y = 456;

int main() {
    x = 67890;
    f();
    printf("x=%d, y=%d\n", x, y);
    return 0;
}
