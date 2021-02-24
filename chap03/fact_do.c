// %rdi = x
long fact_do(long n) {
    long result = 1;
    do {
        result *= n;
        n = n - 1;
    } while (n > 1);
    return result;
}

/* 3.23のコードを転記
dw_loop:
	movq	%rdi, %rax # result = x;
	movq	%rdi, %rcx # y = x;
	imulq	%rdi, %rcx # y = x * x;
	leaq	(%rdi,%rdi), %rdx # rdx = x + x;
.L2:
	leaq	1(%rcx,%rax), %rax # x += y + 1
	subq	$1, %rdx           # n -= 1
	testq	%rdx, %rdx         # nをテスト
	jg	.L2                    # 「n > 0」ならループを繰り返す
	rep: ret
 */
// %rdi = x
long dw_loop(long x) {
    long y = x * x; // rcx
    long *p = &x;
    long n = 2 * x; // rdx
    do {
        x += y;
        (*p)++; // xをインクリメントしている
        n--;
    } while (n > 0);
    return x;
}
