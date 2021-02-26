typedef union {
    struct {
        long u;  // offset:0 (size:8バイト)
        short v; // offset:8 (size:2バイト)
        char w;  // offset:10 (size:1バイト)
    } t1;
    struct {
        int a[2]; // offset:0 (size:8バイト=2*4バイト)
        char *p;  // offset:8 (size:8バイト)
    } t2;
} u_type;

// %rdi = *up, %rsi = *dest
void test_3_43_a(u_type *up, long *dest) {
    // movq (%rdi), %rax
    // movq %rax, (%rsi)
    *dest = up->t1.u;
}

void test_3_43_b(u_type *up, short *dest) {
    // movw 8(%rdi), %ax
    // movw %ax, (%rsi)
    *dest = up->t1.v;
}

void test_3_43_c(u_type *up, char **dest) {
    // addq $10, %rdi
    // movq %rdi, (%rsi)
    *dest = &up->t1.w;
}

void test_3_43_d(u_type *up, int **dest) {
    // movq %rdi, (%rsi)
    *dest = up->t2.a;
}

void test_3_43_e(u_type *up, int *dest) {
    // movq (%rdi), %rax # rax = up->t1.u
    // movl (%rdi,%rax,4), %eax   # rax = rdi + 4 * up->t1.u
    // movl %eax, (%rsi)
    *dest = up->t2.a[up->t1.u];
}

void test_3_43_f(u_type *up, char *dest) {
    // movq 8(%rdi), %rax # rax = up->t2.pのアドレス
    // movb (%rax), al    # rax = up->t2.pの値（charなのでバイト）
    // movb al, (%rsi)
    *dest = *up->t2.p;
}

struct P1 {
    int i;  // offset:0,  size:4
    char c; // offset:4,  size:1 + padding:3
    int j;  // offset:8,  size:4
    char d; // offset:12, size:1 + padding:3
}; // size:16

struct P2 {
    int i;  // offset:0,  size:4
    char c; // offset:4,  size:1
    char d; // offset:5,  size:1 + padding:2
    long j;  // offset:8, size:8
}; // size:16

struct P3 {
    short w[3]; // offset:0, size:6 (=2*3)
    char c[3];  // offset:6, size:3 (=1*3) + padding:1
}; // size:10

struct P4 {
    short w[5]; // offset:0, size:10 (=2*5) + padding:4
    char *c[3]; // offset:16, size:24 (=8*3)
}; // size:40

struct P5 {
    struct P3 a[2]; // offset:0,  size:20 (=10*2) + padding:4
    struct P2 t;    // offset:24, size:16
}; // size:40

struct {
    char *a;  // offset:0,  size:8
    short b;  // offset:8,  size:2 + padding:6
    double c; // offset:16, size:8
    char d;   // offset:24, size:1 + padding:3
    float e;  // offset:28, size:4
    char f;   // offset:32, size:1 + padding:7
    long g;   // offset:40, size:8
    int h;    // offset:48, size:4 + padding:4
} rec; // アラインメント:8、size:56

struct {
    char *a;  // offset:0,  size:8
    double c; // offset:8,  size:8
    long g;   // offset:16, size:8
    float e;  // offset:24, size:4
    int h;    // offset:28, size:4
    short b;  // offset:32, size:2
    char d;   // offset:34, size:1
    char f;   // offset:35, size:1 + padding:4
} rec2; // アラインメント:8、size:40
