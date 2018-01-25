#ifndef __YAVM_BINARY_INSTR_H
#define __YAVM_BINARY_INSTR_H

#include <yavm/instruction.h>

int xor8(instruction_t *instr, stack_t *stack);
int xor16(instruction_t *instr, stack_t *stack);
int xor32(instruction_t *instr, stack_t *stack);
int xor64(instruction_t *instr, stack_t *stack);

int or8(instruction_t *instr, stack_t *stack);
int or16(instruction_t *instr, stack_t *stack);
int or32(instruction_t *instr, stack_t *stack);
int or64(instruction_t *instr, stack_t *stack);

int nor8(instruction_t *instr, stack_t *stack);
int nor16(instruction_t *instr, stack_t *stack);
int nor32(instruction_t *instr, stack_t *stack);
int nor64(instruction_t *instr, stack_t *stack);

int and8(instruction_t *instr, stack_t *stack);
int and16(instruction_t *instr, stack_t *stack);
int and32(instruction_t *instr, stack_t *stack);
int and64(instruction_t *instr, stack_t *stack);

int nand8(instruction_t *instr, stack_t *stack);
int nand16(instruction_t *instr, stack_t *stack);
int nand32(instruction_t *instr, stack_t *stack);
int nand64(instruction_t *instr, stack_t *stack);

int not8(instruction_t *instr, stack_t *stack);
int not16(instruction_t *instr, stack_t *stack);
int not32(instruction_t *instr, stack_t *stack);
int not64(instruction_t *instr, stack_t *stack);

int lshift8(instruction_t *instr, stack_t *stack);
int lshift16(instruction_t *instr, stack_t *stack);
int lshift32(instruction_t *instr, stack_t *stack);
int lshift64(instruction_t *instr, stack_t *stack);

int rshift8(instruction_t *instr, stack_t *stack);
int rshift16(instruction_t *instr, stack_t *stack);
int rshift32(instruction_t *instr, stack_t *stack);
int rshift64(instruction_t *instr, stack_t *stack);

int rol8(instruction_t *instr, stack_t *stack);
int rol16(instruction_t *instr, stack_t *stack);
int rol32(instruction_t *instr, stack_t *stack);
int rol64(instruction_t *instr, stack_t *stack);

int ror8(instruction_t *instr, stack_t *stack);
int ror16(instruction_t *instr, stack_t *stack);
int ror32(instruction_t *instr, stack_t *stack);
int ror64(instruction_t *instr, stack_t *stack);

#endif /* __YAVM_BINARY_INSTR_H */
