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

pC ← valP = 0x02e
```
