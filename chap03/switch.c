/*
switch_eg:
	subq	$100, %rsi
	cmpq	$6, %rsi
	ja	.L8
	jmp	*.L4(,%rsi,8)
.L4:
	.quad	.L7
	.quad	.L8
	.quad	.L6
	.quad	.L5
	.quad	.L3
	.quad	.L8
	.quad	.L3
.L7:
	leaq	(%rdi,%rdi,2), %rax
	leaq	(%rdi,%rax,4), %rdi
	jmp	.L2
.L6:
	addq	$10, %rdi
.L5:
	addq	$11, %rdi
.L2:
	movq	%rdi, (%rdx)
	ret
.L3:
	imulq	%rdi, %rdi
	jmp	.L2
.L8:
	movl	$0, %edi
	jmp	.L2
 */
// %rdi = x, %rsi = n, %rdx = *dest
void switch_eg(long x, long n, long *dest) {
    long val = x;
    switch (n) {
        case 100:
            val *= 13;
            break;
        case 102:
            val += 10;
            /* fall through*/
        case 103:
            val += 11;
            break;
        case 104:
        case 106:
            val *= val;
            break;
        default:
            val = 0;
    }
    *dest = val;
}

// %rdi = a, %rsi = b, %rdx = c, %rcx = *dest
void test_3_31(long a, long b, long c, long *dest) {
    long val; // %rdi
    switch (a) { // a > 7
        case 5: // L7
            c = b ^ 0xF;
            /* fall through*/
        case 0: //L3
            val = c + 112;
            break;
        case 2:
        case 7: // L5
            val = (b + c) << 2;
            break;
        case 4: // L6
            val = a;
            break;
        default: // L2
            val = b;
    }
    *dest = val;
}
