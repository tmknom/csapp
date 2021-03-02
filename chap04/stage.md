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
