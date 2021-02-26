#define M 5
#define N 7

long P[M][N];
long Q[N][M];

/*
 leaq 0(,rdi,8),rdx  # rdx = 8i
 subq rdi, rdx       # rdx = rdx - rdi = 8i - i = 7i
 addq rsi, rdx       # rdx = rdx + rsi = 7i + j
 leaq (rsi,rsi,4),rax# rax = rsi + 4 * rsi = 5j
 addq rax,rdi        # rdi = rdi + rax = i + 5j
 movq Q(,rdi,8),rax  # rax = Q + 8 * rdi = Q + 8 * (i + 5j)
 addq P(,rdx,8),rax  # rax = {P + 8 * (7i + j)} + {Q + 8 * (i + 5j)}
 */
// %rdi = i, %rsi = j, %rax = return value
long test_3_38(long i, long j) {
    return P[i][j] + Q[j][i];
}

#define FIX_N 16
typedef int fix_matrix[FIX_N][FIX_N];

/* -O1オプションでコンパイルした場合
fix_prod_ele:
	salq	$6, %rdx            # rdx = i >> 6 = i * 2^6 = 64 * i
	addq	%rdx, %rdi          # rdi = A + 64 * i = A + 4 * (16 * i + 0)
	leaq	(%rsi,%rcx,4), %rax # rax = B + 4 * k  = B + 4 * (16 * 0 + k)
	leaq	1024(%rax), %rsi    # rsi = B + 4 * k + 4 * 16 * 16 = B + 4 * (16 * 16 + k)
	movl	$0, %ecx
.L2:
	movl	(%rdi), %edx
	imull	(%rax), %edx
	addl	%edx, %ecx
	addq	$4, %rdi
	addq	$64, %rax
	cmpq	%rsi, %rax
	jne	.L2
	movl	%ecx, %eax
	ret
 */
// %rdi = A, %rsi = B, %rdx = i, %rcx = k, %rax = return value
int fix_prod_ele(fix_matrix A, fix_matrix B, long i, long k) {
    long j;
    int result = 0;
    for (j = 0; j < FIX_N; j++) {
        result += A[i][j] * B[j][k];
    }
    return result;
}

int fix_prod_ele_opt(fix_matrix A, fix_matrix B, long i, long k) {
    int *Aptr = &A[i][0];
    int *Bptr = &B[0][k];
    int *Bend = &B[FIX_N][k];
    int result = 0;
    do {
        result += *Aptr * *Bptr;
        Aptr++;
        Bptr += FIX_N;
    } while (Bptr != Bend);
    return result;
}

/* -O1オプションでコンパイルした場合
fix_prod_diag:
	movq	%rdi, %rax       # rax = A
	leaq	1088(%rdi), %rdx # rdx = A + 1088 = A + 1024  + 64 = A + 4 * (16 * 16 + 16) = A[FIX_N][FIX_N]
.L2:
	movl	%esi, (%rax) # M[rax] = *A = val
	addq	$68, %rax    # rax = A + 4 * (16 + 1) = &A[++i][++i]
	cmpq	%rdx, %rax   # rax = rax - A[FIX_N][FIX_N]
	jne	.L2              # A[i][i] != A[FIX_N][FIX_N] then jump L2
	ret
 */
// %rdi = A, %rsi = val, %rax = return value
void fix_prod_diag(fix_matrix A, int val) {
    long i;
    for (i = 0; i < FIX_N; i++) {
        A[i][i] = val;
    }
}

void test_3_40(fix_matrix A, int val) {
    int *Aptr = &A[0][0];
    int *Aend = &A[FIX_N][FIX_N];
    do {
        *Aptr = val;
        Aptr += FIX_N + 1;
    } while (Aptr != Aend);
}

// %rdi = n, %rsi = A, %rdx = B, %rcx = i, %r8 = k, %rax = return value
int var_prod_ele(long n, int A[n][n], int B[n][n], long i, long k) {
    long j;
    int result = 0;
    for (j = 0; j < n; j++) {
        result += A[i][j] * B[j][k];
    }
    return result;
}
