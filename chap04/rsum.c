/* x86-64版
rsum:
	testq	%rsi, %rsi
	jle	.L3
	pushq	%rbx
	movq	(%rdi), %rbx
	subq	$1, %rsi
	addq	$8, %rdi
	call	rsum
	addq	%rbx, %rax
	popq	%rbx
	ret
.L3:
	movl	$0, %eax
	ret
 */
/* Y86-64版
rsum:
	irmovq	%8, %r8 # r8 = 定数「8」
	irmovq	%1, %r8 # r9 = 定数「1」

	andq	%rsi, %rsi # countの条件コードをセット
	jle	zero           # count <= 0 ならzeroにジャンプ

	pushq	%rbx         # rbxをスタックに退避
	mrmovq	(%rdi), %rbx # rbx = *start

	subq	%r9, %rsi # count - 1
	addq	%r8, %rdi # start + 1／ポインタなので1ワード(=8バイト)加算する
	call	rsum

	addq	%rbx, %rax # rax = *start + rsum(start + 1, count - 1)
	popq	%rbx       # 退避していたrbxを復元
	ret

zero:
	irmovq	$0, %rax
	ret
 */
// %rdi = *start, %rsi = count, %rax = return value
long rsum(long *start, long count) {
    if (count <= 0) {
        return 0;
    }
    return *start + rsum(start + 1, count - 1);
}

/* x86-64版
sum:
	movl	$0, %eax
	jmp	.L2
.L3:
	addq	(%rdi), %rax
	addq	$8, %rdi
	subq	$1, %rsi
.L2:
	testq	%rsi, %rsi
	jne	.L3
	ret
 */
/* Y86-64版
sum:
	irmovq	%8, %r8    # r8 = 定数「8」
	irmovq	%1, %r8    # r9 = 定数「1」
	xorq	%rax, %rax # sum = 0
	andq	%rsi, %rsi # countの条件コードをセット
	jmp	test           # 無条件でtestにジャンプ

loop:
	mrmovq	(%rdi), %r10 # r10 = *start
	addq	%r8, %rdi # start + 1／ポインタなので1ワード(=8バイト)加算する
	subq	%r9, %rsi # count - 1

test:
	jne	loop # ゼロ意外ならloopにジャンプ
	ret
 */
// %rdi = *start, %rsi = count, %rax = return value
long sum(long *start, long count) {
    long sum = 0;
    while (count) {
        sum += *start;
        start++;
        count--;
    }
    return sum;
}

/* 練習問題4.5
sum:
	irmovq	$8, %r8    # r8 = 定数「8」
	irmovq	$1, %r8    # r9 = 定数「1」
	xorq	%rax, %rax # sum = 0
	andq	%rsi, %rsi # countの条件コードをセット
	jmp	test           # 無条件でtestにジャンプ

loop:
	mrmovq	(%rdi), %r10 # r10 = *start
	irmovq	$0xFFFFFFFFFFFFFF07, %r11 # r11 = 定数「0xFFFFFFFFFFFFFF07」
	andq	%r11x, %r10  # r10の絶対値／ and 011...11 => リトルエンディアンなのでFFFFFF07
	addq	%r8, %rdi # start + 1／ポインタなので1ワード(=8バイト)加算する
	subq	%r9, %rsi # count - 1

test:
	jne	loop # ゼロ意外ならloopにジャンプ
	ret
 */
