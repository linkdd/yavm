#ifndef __YAVM_STACK_H
#define __YAVM_STACK_H

#include <stdlib.h>
#include <stdint.h>

#define YAVM_MIN_STACK_SIZE 4096

typedef struct stack_s stack_t;
struct stack_s
{
    uint8_t *base;
    size_t size;
    uintptr_t sp;
};

void stack_resize(stack_t *stack);

#endif /* __YAVM_STACK_H */
