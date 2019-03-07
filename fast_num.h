#ifndef __FAST_NUM__
#define __FAST_NUM__

/* 高位全0，低N位全1 */
#define Low_N_Bits_One(N)     ((1<<N) -1)
/* 高位全1，低N位全0 */
#define Low_N_Bits_Zero(N)    (~((1<<N) -1))
/* 低位第N位置1 */
#define Set_Bit_N(NUM, N)     (NUM | (1 << (N - 1)))
/* 低位第N位置0 */
#define Clear_Bit_N(NUM, N)   (NUM & (~(1 << (N - 1))))
/* 低位第N位反转 */
#define Reverse_Bit_N(NUM, N) ((NUM) ^ (1 << (N - 1)))
/* 上取整 */
#define UpRoun8(Num)  (((Num) + 0x7)  & (~0x7))
#define UpRoun16(Num) (((Num) + 0xf)  & (~0xf))
#define UpRoun32(Num) (((Num) + 0x1f) & (~0x1f))
/* 下取整 */
#define LowRoun8(Num)  ((Num) & (~0x7))
#define LowRoun16(Num) ((Num) & (~0xf))
#define LowRoun32(Num) ((Num) & (~0x1f))
/* 求商 */
#define Div8(Num)         ((Num)>>3)
#define Div16(Num)        ((Num)>>4)
#define Div32(Num)        ((Num)>>5)
/* 余数进位求商 */
#define UpDiv8(Num)        (((Num)>>3) + !!((Num) & 0x7))
#define UpDiv16(Num)        (((Num)>>4) + !!((Num) & 0xf))
#define UpDiv32(Num)        (((Num)>>5) + !!((Num) & 0x1f))
/* 求余 */
#define M8(Num)        ((Num) & 0x7)
#define M16(Num)       ((Num) & 0xf)
#define M32(Num)       ((Num) & 0x1f)
/* 求反余
即求最小的x，满足(Num + x) % 模数 == 0
例如 RM16(Num) 等价于 (16 - Num%16) % 16 */
#define RM8(Num)        ((~(Num) + 1) & 0x7)
#define RM16(Num)        ((~(Num) + 1) & 0xf)
#define RM32(Num)        ((~(Num) + 1) & 0x1f)


#endif