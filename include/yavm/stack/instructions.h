#ifndef __YAVM_STACK_INSTR_H
#define __YAVM_STACK_INSTR_H

#include <yavm/instruction.h>

int push8(instruction_t *instr, stack_t *stack);
int push16(instruction_t *instr, stack_t *stack);
int push32(instruction_t *instr, stack_t *stack);
int push64(instruction_t *instr, stack_t *stack);

int pop8(instruction_t *instr, stack_t *stack);
int pop16(instruction_t *instr, stack_t *stack);
int pop32(instruction_t *instr, stack_t *stack);
int pop64(instruction_t *instr, stack_t *stack);

int swap8(instruction_t *instr, stack_t *stack);
int swap16(instruction_t *instr, stack_t *stack);
int swap32(instruction_t *instr, stack_t *stack);
int swap64(instruction_t *instr, stack_t *stack);

int tuck8(instruction_t *instr, stack_t *stack);
int tuck16(instruction_t *instr, stack_t *stack);
int tuck32(instruction_t *instr, stack_t *stack);
int tuck64(instruction_t *instr, stack_t *stack);

#endif /* __YAVM_STACK_INSTR_H */
