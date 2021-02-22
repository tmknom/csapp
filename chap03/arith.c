// %rdi = x, %rsi = y, %rdx = z, %rax = return value
long arith(long x, long y, long z) {
    long t1 = x ^y;
    long t2 = z * 48;
    long t3 = t1 & 0x0F0F0F0F;
    long t4 = t2 - t3;
    return t4;
}

// %rdi = x, %rsi = y, %rdx = z, %rax = return value
long arith2(long x, long y, long z) {
    long t1 = x ^y;
    long t2 = t1 >> 3;
    long t3 = ~t2;
    long t4 = z - t3;
    return t4;
}
