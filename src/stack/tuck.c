#include <yavm/instruction.h>
#include <string.h>

int tuck8(instruction_t *instr, stack_t *stack)
{
    uint8_t val1 = 0, val2 = 0;

    memcpy(&val1, stack->base + stack->sp - 1, sizeof(val1));
    memcpy(&val2, stack->base + stack->sp - 2, sizeof(val2));

    memcpy(stack->base + stack->sp,     &val1, sizeof(val1));
    memcpy(stack->base + stack->sp - 1, &val2, sizeof(val2));
    memcpy(stack->base + stack->sp - 2, &val1, sizeof(val1));

    stack->sp += 1;

    return 0;
}

int tuck16(instruction_t *instr, stack_t *stack)
{
    uint16_t val1 = 0, val2 = 0;

    memcpy(&val1, stack->base + stack->sp - 2, sizeof(val1));
    memcpy(&val2, stack->base + stack->sp - 4, sizeof(val2));

    memcpy(stack->base + stack->sp,     &val1, sizeof(val1));
    memcpy(stack->base + stack->sp - 2, &val2, sizeof(val2));
    memcpy(stack->base + stack->sp - 4, &val1, sizeof(val1));

    stack->sp += 2;

    return 0;
}

int tuck32(instruction_t *instr, stack_t *stack)
{
    uint32_t val1 = 0, val2 = 0;

    memcpy(&val1, stack->base + stack->sp - 4, sizeof(val1));
    memcpy(&val2, stack->base + stack->sp - 8, sizeof(val2));

    memcpy(stack->base + stack->sp,     &val1, sizeof(val1));
    memcpy(stack->base + stack->sp - 4, &val2, sizeof(val2));
    memcpy(stack->base + stack->sp - 8, &val1, sizeof(val1));

    stack->sp += 4;

    return 0;
}

int tuck64(instruction_t *instr, stack_t *stack)
{
    uint64_t val1 = 0, val2 = 0;

    memcpy(&val1, stack->base + stack->sp - 8,  sizeof(val1));
    memcpy(&val2, stack->base + stack->sp - 16, sizeof(val2));

    memcpy(stack->base + stack->sp, &val1,      sizeof(val1));
    memcpy(stack->base + stack->sp - 8, &val2,  sizeof(val2));
    memcpy(stack->base + stack->sp - 16, &val1, sizeof(val1));

    stack->sp += 8;

    return 0;
}
