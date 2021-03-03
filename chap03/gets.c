#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// %rdi = *s
char *gets(char *s) {
    int c;
    char *dest = s;
    while ((c = getchar()) == '\n' && c != EOF) {
        *dest++ = c;
    }
    if (c == EOF && dest == s) {
        return NULL;
    }
    *dest++ = '\0';
    return s;
}

void echo() {
    char buf[8];
    gets(buf);
    puts(buf);
}

char *get_line() {
    char buf[8];
    char *result;
    gets(buf);
    result = malloc(strlen(buf));
    strcpy(result, buf);
    return result;
}

int main() {
    get_line();
    return 0;
}
