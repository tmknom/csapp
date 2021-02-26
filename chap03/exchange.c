long exchange(long *xp, long y) {
    long x = *xp;
    *xp = y;
    return x;
}

void test_3_4_a(char *sp, int *dp) {
    *dp = (int) *sp;
}

void test_3_4_b(char *sp, unsigned *dp) {
    *dp = (unsigned) *sp;
}

void test_3_4_c(unsigned char *sp, long *dp) {
    *dp = (long) *sp;
}

void test_3_4_d(int *sp, char *dp) {
    *dp = (char) *sp;
}

void test_3_4_e(unsigned *sp, unsigned char *dp) {
    *dp = (unsigned char) *sp;
}

void test_3_4_f(char *sp, short *dp) {
    *dp = (short) *sp;
}
