// %rdi = i, %rsi = *fp, %rdx = *dp, %rcx = *lp, %rax = return value
double fbct(int i, float *fp, double *dp, long *lp) {
    float f = *fp;
    double d = *dp;
    long l = *lp;

    *lp = (long) d;
    *fp = (float) i;
    *dp = (double) l;

    return (double) f;
}

/*
fbct2:
	movl	(%rdi), %eax     # rax = i = ipの値
	movss	(%rsi), %xmm0    # xmm0 = f = fpの値

	cvttsd2si	(%rdx), %r8d # r8d = d = dpの値を整数に変換
	movl	%r8d, (%rdi)     # rdi = *ip = 整数変換済みのdpの値（*ip = (int) d;）

	cvttsi2ss	%eax, %xmm1, %xmm1 # xmm1 = i = ipの値をfloatに変換
	movss	%xmm1, (%rsi)    # *fp = float変換済みのipの値（*fp = (float) i;）

	cvtsi2sdq	%rcx, %xmm1, %xmm1 # xmm1 = lをdoubleに変換
	movsd	%xmm1, (%rdx)          # rdx = *dp = double変換済みのl（*dp = (double) l;）

	unpckplps	%xmm0, %xmm0, %xmm0 # xmm0 = fをdoubleに変換
	cvtps2pd	%xmm0, %xmm0
	ret
 */
// %rdi = *ip, %rsi = *fp, %rdx = *dp, %rcx = l, %rax = return value
double fbct2(int *ip, float *fp, double *dp, long l) {
    int i = *ip;
    float f = *fp;
    double d = *dp;

    *ip = (int) d;
    *fp = (float) i;
    *dp = (double) l;

    return (double) f;
}

// %rdi = p, %rsi = q, %rdx = r, %rcx = s, %rax = return value
double test_3_53(int p, long q, float r, double s) {
    // xmm2 = q → float
    // vaddss xmm0 + xmm2
    // xmm0 = q+r
    // xmm2 = p → float
    // xmm0 = p / (q+r)
    return p / (q + r) - s;
}

// %xmm0 = w, %rdi = x, %xmm1 = y, %rsi = z, %rax = return value
double test_3_54(double w, int x, float y, long z) {
    // xmm2 = (float) x
    // xmm1 = y = (float) x / y
    // xmm2 = (double)( (float) x * y )
    // xmm1 = (double) z
    // xmm0 = w / (double) z
    // xmm0 = (double)( (float) x * y ) - w / (double) z
    return ((double) ((float) x * y)) - (w / (double) z);
}

// 0x 4040 0000 0000 0000
// 上位6桁 = 0x4 0 4 = 4 * 16 * 16 +  4= 2^(2 + 4 +4) + 4 = 2^10+4= 1024+4= 1028
// 1028 - 1023 = 5 (=2^5)
// 指数部は0x404 = 1028である
// バイアスが2^(11-1)-1 = 1024 -1 = 1023
// よってE = 1028 - 1023 = 5
// 仮数は0x0なので暗黙の1と乗算すると2^5 * 1.0 = 32.0となる
double test_3_55(double temp) {
    return 1.8 * temp + 32.0;
}

// %rdi = *ap, %xmm0 = b, %rsi = c, %rdx = dp, %rax = return value
double test_3_57(int *ap, double b, long c, float *dp) {
    if (b > (double) *ap) { // 符号なし <=
        return (double) (*dp * (float) c);
    }
    // L8
    return (double) ((float) c + 2 * (*dp));
}
