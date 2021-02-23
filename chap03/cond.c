/*
cond:
	testq	%rsi, %rsi   # pがゼロならZFを立てるためテスト
	je	.L1              # ZFがゼロならL1にジャンプ（=returnする）
	cmpq	%rdi, (%rsi) # 「*p - x」を計算し、条件フラグをセット
	jge	.L1              # 「*p >= x」ならL1にジャンプ（=returnする）
	movq	%rdi, (%rsi) # 「*p = x」を実行（is-statement）
.L1:
	ret
 */
// %rdi = x, %rsi = *p
void cond(long a, long *p) {
    if (p && a > *p)
        *p = a;
}

void goto_cond(long a, long *p) {
    if (!p)
        goto return_void;
    if (*p <= a)
        goto return_void;

    *p = a;

    return_void:;
}

// %rdi = x, %rsi = y, %rdx = z
long test(long x, long y, long z) {
    long val = x + y + z;

    if (x < -3) {
        if (y < z) {
            val = x * y;
        } else {
            val = y * z;
        }
    } else if (x > 2) {
        val = x * z;
    }

    return val;
}
