/*
 * test 3.32
 * label    pc,    rdi rsi rax,       rsp        *rsp,     desc
 * 0x400560 callq, 10   -   - , 0x7fffffffe820   -       , Call first(10)
 * 0x400548 lea,   10   -   - , 0x7fffffffe818   0x400565, x+1
 * 0x40054c sub,   10   11  - , 0x7fffffffe818   0x400565, x-1
 * 0x400550 callq,  9   11  - , 0x7fffffffe818   0x400565, Call last(x-1, x+1)
 * 0x400540 mov,    9   11  - , 0x7fffffffe810   0x400555, u
 * 0x400543 imul,   9   11  9 , 0x7fffffffe810   0x400555, u*v
 * 0x400547 retq,   9   11  99, 0x7fffffffe810   0x400555, Return
 * 0x400555 retq,   9   11  99, 0x7fffffffe818   0x400565, Return
 * 0x400565 retq,   9   11  99, 0x7fffffffe820   -       , Resume
 */
// %rdi = x, %rsi = y, %rax = return value
long last(long x, long y) {
    return x * y;
}

long first(long x) {
    return last(x - 1, x + 1);
}

int main() {
    long x = first(10);
    long y = x << 3;
    return y;
}

/*
proc:
	movq	16(%rsp), %rax
	addq	%rdi, (%rsi)
	addl	%edx, (%rcx)
	addw	%r8w, (%r9)
	movl	8(%rsp), %edx
	addb	%dl, (%rax)
	ret
 */
// %rdi = a1, %rsi = *a1p
// %rdx = a2, %rcx = *a2p
// %r8  = a3, %r9  = *a3p
// %rsp+8 = a4, %rsp+16 = *a4p
// スタック = [戻りアドレス, 第7引数(a4), 第8引数(*a4p)]
void proc(long a1, long *a1p,
          int a2, int *a2p,
          short a3, short *a3p,
          char a4, char *a4p) {
    *a1p += a1;
    *a2p += a2;
    *a3p += a3;
    *a4p += a4;
}

/*
 movslq %edi, rdi // 第1引数を符号付きで4バイトから8バイトへ拡張
 addq %rdi, (%rdx) // 第3引数に第1引数（8バイト）を加算
 addb %sil, (%rcx) // 第2引数（1バイト）を第4引数に加算
 movl $6, %eax // return値を6にセット（2バイト+4バイト）
 */
// %rdi = a1, %rsi = *a1p, %rdx = a2, %rcx = *a2p
int test_3_33(int a, short b, long *u, char *v) {
    *u += a;
    *v += b;
    return sizeof(a) + sizeof(b);
}

long swap_add(long *xp, long *yp) {
    long x = *xp;
    long y = *yp;
    *xp = y;
    *yp = x;
    return x + y;
}

long caller() {
    long arg1 = 534;
    long arg2 = 1057;
    long sum = swap_add(&arg1, &arg2);
    long diff = arg1 - arg2;
    return sum * diff;
}

long call_proc() {
    long x1 = 1;
    int x2 = 2;
    short x3 = 3;
    char x4 = 4;
    proc(x1, &x1, x2, &x2, x3, &x3, x4, &x4);
    return (x1 + x1) * (x3 - x4);
}

long Q(long x) {
    return 2 + x * 3;
}

/*
P:
	pushq	%rbp
	pushq	%rbx
	movq	%rdi, %rbp
	movq	%rsi, %rdi
	call	Q
	movq	%rax, %rbx
	movq	%rbp, %rdi
	call	Q
	addq	%rbx, %rax
	popq	%rbx
	popq	%rbp
	ret
 */
long P(long x, long y) {
    long u = Q(y);
    long v = Q(x);
    return u + v;
}

// 引数xをスタックに退避
// result = 0;
// 引数xでテスト
// if(x = 0) { L2にジャンプ }
long test_3_35(unsigned long x) {
    if (x == 0) {
        return x;
    }
    unsigned long nx = x >> 2;
    long rv = test_3_35(nx);

    return x + rv;
}
