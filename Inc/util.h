#ifndef util_H
#define util_H

#define SetBit(Reg,Bit)   Reg |= (1<<Bit)
#define ClrBit(Reg,Bit)   Reg &= ~(1<<Bit)
#define GetBit(Reg,Bit)   ((Reg>>Bit) & (0x01))
#define InsertBit(Reg,Bit,Val) Reg = (Reg & ~(1<<Bit)) + (Val<<Bit)
#define InsertField(Reg,Mask,Field,StartBit) Reg = (Reg & Mask) + (Field<<StartBit)
// Mask must be the same size of Reg

#endif
