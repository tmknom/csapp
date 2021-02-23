#include <inttypes.h>

typedef unsigned __int128 uint128_t;

/*
store_uprod:
	movq	%rsi, %rax
	mulq	%rdx
	movq	%rax, (%rdi)
	movq	%rdx, 8(%rdi)
	ret
 */
// %rdi = dest, %rsi = x, %rdx = y, %rax = return value
void store_uprod(uint128_t *dest, uint64_t x, uint64_t y) {
    *dest = x * (uint128_t) y;
}

/*
remdiv:
	movq	%rdi, %rax   # %raxにxをコピー
	movq	%rdx, %rdi   # %rdiにqpをコピー
	cqto                 # %rax(=x)の符号ビットを、%rdxの全ビットにコピー
	idivq	%rsi         # %rax(=商) = [%rdx:%rax(=x)] / y、%rdx(=余り)=[%rdx:%rax(=x)] % y
	movq	%rax, (%rdi) # M[%rdi](=*qp) = %rax(=商)
	movq	%rdx, (%rcx) # M[%rcx](=*rp) = %rdx(=余り)
	ret
 */
// %rdi = x, %rsi = y, %rdx = qp, %rcx = rp, %rax = return value
void remdiv(long x, long y, long *qp, long *rp) {
    long q = x / y; // 商
    long r = x % y; // 余り
    *qp = q;
    *rp = r;
}

/*
uremdiv:
	movq	%rdi, %rax   # %raxにxをコピー
	movq	%rdx, %rdi   # %rdiにqpをコピー
	movl    $0, %edx     # %rdxの全ビットをゼロにする（movlのdestがレジスタの場合、上位4バイトも自動でゼロ埋めされる）
	divq	%rsi         # %rax(=商) = [%rdx:%rax(=x)] / y、%rdx(=余り)=[%rdx:%rax(=x)] % y
	movq	%rax, (%rdi) # M[%rdi](=*qp) = %rax(=商)
	movq	%rdx, (%rcx) # M[%rcx](=*rp) = %rdx(=余り)
	ret
 */
// %rdi = x, %rsi = y, %rdx = qp, %rcx = rp, %rax = return value
void uremdiv(unsigned long x, unsigned long y, unsigned long *qp, unsigned long *rp) {
    long q = x / y; // 商
    long r = x % y; // 余り
    *qp = q;
    *rp = r;
}
