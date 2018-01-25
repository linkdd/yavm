#ifndef __YAVM_INSTRUCTION_H
#define __YAVM_INSTRUCTION_H

#include <yavm/stack.h>
#include <stdint.h>

#define NB_INSTRUCTIONS     32
#define INSTR_SIZE_8        0
#define INSTR_SIZE_16       1
#define INSTR_SIZE_32       2
#define INSTR_SIZE_64       3

typedef struct instruction_s instruction_t;
struct instruction_s
{
    uint8_t has_operand : 1;
    uint8_t opcode      : 5;
    uint8_t size        : 2;
} __attribute__((packed));

typedef int (*ihandler_t) (instruction_t *, stack_t *);

int do_instruction(instruction_t *instr, stack_t *stack);

#endif /* __YAVM_INSTRUCTION_H */
