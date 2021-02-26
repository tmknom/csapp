// %rdi = x, %rsi = y
long absdiff(long x, long y) {
    long result;

    if (x < y) {
        result = y - x;
    } else {
        result = x - y;
    }

    return result;
}

/* -O1オプションでコンパイルした場合
cmovdiff:
	movq	%rsi, %rdx
	subq	%rdi, %rdx
	movq	%rdi, %rax
	subq	%rsi, %rax
	cmpq	%rdi, %rsi
	cmovg	%rdx, %rax
	ret
 */
long cmovdiff(long x, long y) {
    long rval = y - x;
    long eval = x - y;
    long ntest = x >= y;
    if (ntest) rval = eval;
    return rval;
}

/*
 leaq 7(%rdi), %rax   # result = x + 7
 testq rdi, rdi       # xの正負とゼロの判定をして条件フラグをセット
 cmovns rdi, rax      # if(x > 0) {result = x}
 sarq $3, rax         # if(x > 0) {result = x >> 3}              # 正の数の演算：x / 8
                      # else if(x <= 0) {result = (x + 7) >> 3}  # 負の数の演算：(x + 7) / 8
 */
// %rdi = x
long arith(long x) {
    return x / 8;
}

/*
 leaq    # result = x * 8
 testq   # yの正負とゼロの判定をして条件フラグをセット
 jle .L2 # 「y <= 0」ならL2へジャンプ

 movq # result = y
 subq # result = y - x
 movq # tmp = x
 addq # tmp = x + y
 cmpq # x - y
 cmovge # if(x >= y) {result = tmp (= x + y)}

 .L2:
    addq   # x = x + y
    cmpq   # y - (-2)
    cmovle # if(y <= -2) {result = x + y}
 */
// %rdi = x, %rsi = y, %rax = return value
long test_3_21(long x, long y) {
    long val = x * 8;

    if (y > 0) {
        if (x < y) {
            val = y - x;
        } else {
            val = y & x;
        }
    } else if (y <= -2) {
        val = x + y;
    }

    return val;
}
