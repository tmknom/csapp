/* -Ogオプションでコンパイルした場合
continue_for:
	movl	$0, %eax
	jmp	.L2
.L3:
	addq	$1, %rax
.L2:
	cmpq	$9, %rax
	jle	.L3
	ret
 */
void continue_for() {
    long sum = 0;
    long i;
    for (i = 0; i < 10; i++) {
        if (i & 1) {
            continue;
        }
        sum += i;
    }
}

long continue_for_while() {
    long sum = 0;
    long i = 0;
    while (i < 10) {
        if (i & 1) {
            continue; // iが更新されないため無限ループになる
        }
        sum += i;
        i++;
    }
    return sum;
}

long continue_for_goto() {
    long sum = 0;
    long i = 0;
    while (i < 10) {
        if (i & 1) {
            goto update;
        }
        sum += i;
update:
        i++;

    }
    return sum;
}
