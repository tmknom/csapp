long lt_cnt = 0;
long ge_cnt = 0;

// %rdi = x, %rsi = y, %rax = return value
long absdiff_se(long x, long y) {
    long result;
    if (x < y) {
        lt_cnt++;
        result = y - x;
    } else {
        ge_cnt++;
        result = x - y;
    }
    return result;
}

long gotodiff_se(long x, long y) {
    long result;
    if (x >= y) {
        goto x_ge_y;
    }
    lt_cnt++;
    result = y - x;
    return result;

    x_ge_y:
    ge_cnt++;
    result = x - y;
    return result;
}

long gotodiff_else_se(long x, long y) {
    long result;
    if (x < y) {
        goto x_lt_y;
    }
    ge_cnt++;
    result = x - y;
    return result;

    x_lt_y:
    lt_cnt++;
    result = y - x;
    return result;
}
