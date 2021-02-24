/* -Ogオプションでコンパイルした場合
fact_while:
	movl	$1, %eax
	jmp	.L2
.L3:
	imulq	%rdi, %rax
	subq	$1, %rdi
.L2:
	cmpq	$1, %rdi
	jg	.L3
	ret
 */
/* -O1オプションでコンパイルした場合
fact_while:
	cmpq	$1, %rdi
	jle	.L4
	movl	$1, %eax
.L3:
	imulq	%rdi, %rax
	subq	$1, %rdi
	cmpq	$1, %rdi
	jne	.L3
	ret
.L4:
	movl	$1, %eax
	ret
 */
// %rdi = x
long fact_while(long n) {
    long result = 1;
    while (n > 1) {
        result *= n;
        n = n - 1;
    }
    return result;
}

long fact_while_jm_goto(long n) {
    long result = 1;
    goto test;

loop:
    result *= n;
    n = n - 1;

test:
    if (n > 1) {
        goto loop;
    }
    return result;
}

long fact_while_gd_goto(long n) {
    long result = 1;
    if (n <= 1) {
        goto done;
    }

loop:
    result *= n;
    n = n - 1;
    if (n != 1) {
        goto loop;
    }

done:
    return result;
}

/* -Ogオプションでコンパイルした場合
test_3_24:
	movl	$1, %eax
	jmp	.L2
.L3:
	leaq	(%rdi,%rsi), %rdx
	imulq	%rdx, %rax
	addq	$1, %rdi
.L2:
	cmpq	%rsi, %rdi
	jl	.L3
	ret
 */
// %rdi = a, %rsi = b, %rax = return value
long test_3_24(long a, long b) {
    long result = 1;
    while (a < b) {
        result = result * (a + b);
        a = a + 1;
    }
    return result;
}

// %rdi = a, %rsi = b, %rax = return value
long test_3_25(long a, long b) {
    long result = b;
    while (b > 0) {
        result = result * a;
        b = b - a;
    }
    return result;
}

// %rdi = x %rax = return value
long test_3_26(unsigned long x) {
    long val = 0;
    while (x != 0) {
        val = val ^ x;
        x >>= 1;
    }
    return val & 1;
}
