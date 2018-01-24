#ifndef __YAVM_VM_H
#define __YAVM_VM_H

#include <yavm/instruction.h>
#include <yavm/stack.h>

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>


typedef struct program_s program_t;
struct program_s
{
    instruction_t *code;
    size_t size;
    uintptr_t ip;
};

typedef struct vm_s vm_t;
struct vm_s
{
    program_t prog;
    stack_t stack;
    bool halted;
    int retcode;
};

vm_t *vm_new (void);
void vm_delete(vm_t *vm);

void vm_load(vm_t *vm, program_t *prog);
void vm_step(vm_t *vm);
bool vm_halted(vm_t *vm, int *retcode);

program_t *program_new_from_file(FILE *fin);
program_t *program_new_from_memory(uint8_t *mem, size_t size);

#endif /* __YAVM_VM_H */
