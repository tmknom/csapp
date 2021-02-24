/* -Ogオプションでコンパイルした場合
fact_for:
	movl	$1, %edx
	movl	$2, %eax
	jmp	.L2
.L3:
	imulq	%rax, %rdx
	addq	$1, %rax
.L2:
	cmpq	%rdi, %rax
	jle	.L3
	movq	%rdx, %rax
	ret
 */
// %rdi = x
long fact_for(long n) {
    long i;
    long result = 1;
    for (i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

long fact_for_while(long n) {
    long i = 2;
    long result = 1;
    while (i <= n) {
        result *= i;
        i++;
    }
    return result;
}

long fact_for_jm_goto(long n) {
    long i = 2;
    long result = 1;
    goto test;

loop:
    result *= i;
    i++;

test:
    if (i <= n)
        goto loop;

    return result;
}

long fact_for_gd_goto(long n) {
    long i = 2;
    long result = 1;
    if (i > n)
        goto done;

loop:
    result *= i;
    i++;
    if (i <= n)
        goto loop;

done:
    return result;
}

/* -O1オプションでコンパイルした場合
test_3_28:
	movl	$64, %edx
	movl	$0, %eax
.L2:
	movq	%rdi, %rcx
	andl	$1, %ecx
	addq	%rax, %rax
	orq	%rcx, %rax
	shrq	%rdi
	subq	$1, %rdx
	jne	.L2
	ret
 */
// %rdi = x
long test_3_28(unsigned long x) {
    long val = 0; // eax
    long i; // edx
    for (i = 64; i > 0; --i) {
        val = (val << 1) | (x & 1);
        x >>= 1;
    }
    return val;
}
