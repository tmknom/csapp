# stage

## 4.13

```
# 30f480...00 irmovq $128, %rsp

icode:ifun ← M1[0x016] = 3:0
rA:rB ← M1[0x017] = f:4
valC ← M8[0x018] = 128
valP ← PC + 10 = 0x020

valE ← 0 + valC = 128

R[rb] ← valE = R[%rsp] ← 128

PC ← ValP = 0x020
```

## 4.14

### 手前の処理

```
R[rdx] = 9
R[rbx] = 21
R[rbx] = 12 # sub %rdx, %rbx
R[rsp] = 128
M[112] = 128 # rmmovq %rsp, 100(%rbx)
push 9 # pushq %rdx／R[rsp] = 128 - 8 = 120／M8[120] = 9
```

### 回答

```
# b00f pop %rax

icode:ifun ← M1[0x02c] = b:0
rA:rB ← M1[0x02d] = 0:f
valP ← PC + 2 = 0x02e

valA ← R[%rsp] = 120
valB ← R[%rsp] = 120

valE ← valB + 8 = 128

valM ← M8[valA] =M8[120] = 9

R[rsp] ← valE = 128
R[rA] ← valM = R[rax] = 9

PC ← valP = 0x02e
```

## 4.15

4.7と同様にpush実行直前のrspをスタックに積む

```
# a04f push %rsp

icode:ifun ← M1[PC] = a:0
rA:rB ← M1[PC+1] = 4:f
valP ← PC + 2

valA ← R[rA]
valB ← R[%rsp]

valE ← valB + (-8) = R[%rsp] - 8

M8[valE] ← valA = R[rA] = R[%rsp] # 古いSPを積む

R[rsp] ← valE = R[%rsp] - 8

PC ← valP = PC + 2
```

## 4.16

4.8と同様にpop実行直前にスタックに積まれていた値をrspにセットする

```
# b04f pop %rsp

icode:ifun ← M1[PC] = b:0
rA:rB ← M1[PC+1] = 4:f
valP ← PC + 2

valA ← R[%rsp] # pop実行直前のrsp
valB ← R[%rsp] # pop実行直前のrsp

valE ← valB + 8 = R[%rsp] + 8 # pop実行後のrspの値の算出

valM ← M8[valA] # スタックに積まれていた値をvalMにセット

R[rsp] ← valE # rspに正しい値をセット
R[rA] ← valM  # R[rsp] = valM = スタックに積まれていた値をrspをセット

PC ← valP = PC + 2
```

## 4.17

```
# cmovXX rA, rB

# フェッチ
icode:ifun ← M1[PC]
rA:rB ← M1[PC+1]
valP ← PC + 2

# デコード
valA ← R[rA]    # valAにrAの値を代入
valB ← R[rB]    # valBにrBの値を代入

# 実行
Cnd ← Cond(CC, ifun)     # 条件チェック
valE ← Cnd ? valA : valB # 条件を満たすならrAの値を代入、満たさないならrBの値を代入

# ライトバック
R[rB] ← valE    # R[rB]にvalEを代入

# PCアップデート
PC ← valP
```

## 4.18

```
# 804100..00 call 0x041

icode:ifun ← M1[0x037] = 8:0
valC ← M8[0x038] = 0x41
valP ← PC + 9 = 0x040

valB ← R[%rsp] = 128

valE ← valB + (-8) = 120

M8[valE] ← valP = M8[120] ← 0x040

R[rsp] ← valE = R[rsp] ← 120

PC ← valC = 0x41
```

## 4.19

```
bool need_valC = icode in {
    IIRMOVQ, IRMMOVQ, IMRMOVQ, IJXX, ICALL
};
```

## 4.20

```
word srcB = [
    icode in {IOPQ, IRMMOVQ, IMRMOVQ} : rA;
    icode in {IPUSHQ, IPOPQ, ICALL, IRET} : RRSP;
    1: RNONE;
];
```

## 4.21

```
word dstM = [
    icode in {IMRMOVQ, IPOPQ} : rA;
    1: RNONE;
];
```

## 4.23

```
word aluB = [
    icode in {IPOPQ, IRMMOVQ, IMRMOVQ, IPUSHQ, IPOPQ, ICALL, IRET} : valB;
    icode in {IRRMOVQ, IIRMOVQ} : 0;
];
```

## 4.24

```
word dstE = [
    icode in {IRRMOVQ} && Cnd : rA;
    ......
];
```

## 4.25

```
word mem_data = [
    icode in {IRMMOVQ, IPUSHQ} : valA;
    icode in {ICALL} : valP;
];
```

## コピペ用定数定義

```
##### Symbolic representation of Y86-64 Instruction Codes #############
wordsig INOP 	'I_NOP'
wordsig IHALT	'I_HALT'
wordsig IRRMOVQ	'I_RRMOVQ'
wordsig IIRMOVQ	'I_IRMOVQ'
wordsig IRMMOVQ	'I_RMMOVQ'
wordsig IMRMOVQ	'I_MRMOVQ'
wordsig IOPQ	'I_ALU'
wordsig IJXX	'I_JMP'
wordsig ICALL	'I_CALL'
wordsig IRET	'I_RET'
wordsig IPUSHQ	'I_PUSHQ'
wordsig IPOPQ	'I_POPQ'

##### Symbolic represenations of Y86-64 function codes                  #####
wordsig FNONE    'F_NONE'        # Default function code

##### Symbolic representation of Y86-64 Registers referenced explicitly #####
wordsig RRSP     'REG_RSP'    	# Stack Pointer
wordsig RNONE    'REG_NONE'   	# Special value indicating "no register"

##### ALU Functions referenced explicitly                            #####
wordsig ALUADD	'A_ADD'		# ALU should add its arguments

##### Possible instruction status values                             #####
wordsig SAOK	'STAT_AOK'	# Normal execution
wordsig SADR	'STAT_ADR'	# Invalid memory address
wordsig SINS	'STAT_INS'	# Invalid instruction
wordsig SHLT	'STAT_HLT'	# Halt instruction encountered
```
