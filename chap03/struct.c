struct prob {
    int *p; // offset:0 (8バイト)
    struct {
        int x; // offset:8 (4バイト)
        int y; // offset:12 (4バイト)
    } s;
    struct prob *next; // offset:16 (8バイト)
}; // 合計24バイト

/*
 movl 12(%rdi), %eax # rax = sp->s.y
 movl %eax, 8(%rdi)  # sp->s.x = sp->s.y
 leaq 8(%rdi), %rax  # rax = sp->s.x
 movq %rax, (%rdi)   # sp->p = sp->s.x
 movq %rdi, 16(%rdi) # sp->next = sp->p
 */
// %rdi = *sp
void test_3_41(struct prob *sp) {
    sp->s.x = sp->s.y;
    sp->p = &(sp->s.x);
    sp->next = sp;
}

struct ELE {
    long v;
    struct ELE *p;
};

/*
test_3_42:
	movl	$0, %eax
	jmp	.L2
.L3:
	addq	(%rdi), %rax
	movq	8(%rdi), %rdi
.L2:
	testq	%rdi, %rdi
	jne	.L3
	ret
 */
// %rdi = *ptr, %rax = return value
long test_3_42(struct ELE *ptr) {
    long result = 0;

    while (ptr != 0) {
        result += ptr->v;
        ptr = ptr->p;
    }
    return result;
}
