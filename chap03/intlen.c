#include <stdio.h>
#include <string.h>

// %rdi = *s
int len(char *s) {
    return strlen(s);
}

void iptoa(char *s, long *p) {
    long val = *p;
    sprintf(s, "%ld", val);
}

/*
# スタック保護無効
# bufはスタックの先頭、vはスタックの24バイト目
intlen:
	subq	$40, %rsp      # スタックを40バイト確保
	movq	%rdi, 24(%rsp) # スタックの24〜31バイトへ引数xを保存
	leaq	24(%rsp), %rsi # 引数xのアドレスをrsiレジスタに保存(&vの生成)
	movq	%rsp, %rdi     # スタックの先頭アドレスをrdiに保存
	call	iptoa          # iptoa(buf, &v)

# スタック保護有効：-fstack-protectorオプションをつけてコンパイルする
# bufはスタックの16バイト目、vはスタックの8バイト目、カナリア値はスタックの40バイト目
# bufがバッファ・オーバーフローしてもvの値は上書きされなくて済む
intlen:
	subq	$56, %rsp      # スタックを56バイト確保
	movq	%fs:40, %rax   # raxに8バイトのカナリア値を保存
	movq	%rax, 40(%rsp) # カナリア値をスタックの40バイト目に保存（40〜47バイト）
	xorl	%eax, %eax     # raxをゼロ埋め
	movq	%rdi, 8(%rsp)  # スタックの8バイト目（8〜15バイト）に引数xを保存
	leaq	8(%rsp), %rsi  # 引数xのアドレスをrsiに保存
	leaq	16(%rsp), %rdi # スタックの16バイト目のアドレスをrdiに保存
	call	iptoa
 */
int intlen(long x) {
    long v; // 8バイト
    char buf[12]; // 12バイト
    v = x;
    iptoa(buf, &v); // 8バイト（&v生成時に必要）
    return len(buf);
}
