/*
comp:
	cmpq	%rsi, %rdi
	setl	%al
	movzbl	%al, %eax
	ret
 */
// %rdi = x, %rsi = y, %rax = return value
int comp(long x, long y) {
    return x < y;
}

// %rdi = a, %rsi = b, %rax = return value
int test_3_13_a(int a, int b) {
    return a < b;
}

int test_3_13_b(short a, short b) {
    return a >= b;
}

int test_3_13_c(unsigned char a, unsigned char b) {
    return a <= b;
}

int test_3_13_d(long a, long b) {
    return a != b;
}

// %rdi = a, %rax = return value
int test_3_14_a(long a) {
    return a >= 0;
}

int test_3_14_b(short a) {
    return a == 0;
}

int test_3_14_bb(unsigned short a) {
    return a == 0;
}

int test_3_14_c(unsigned char a) {
    return a > 0;
}

int test_3_14_d(int a) {
    return a <= 0;
}
