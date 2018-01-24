#include <yavm/instruction.h>
#include <string.h>

int swap8(instruction_t *instr, stack_t *stack)
{
    uint8_t val1 = 0, val2 = 0, vali = 0;

    memcpy(&val1, stack->base + stack->sp - 1, sizeof(val1));
    memcpy(&val2, stack->base + stack->sp - 2, sizeof(val2));

    vali = val2;
    val2 = val1;
    val2 = vali;

    memcpy(stack->base + stack->sp - 1, &val1, sizeof(val1));
    memcpy(stack->base + stack->sp - 2, &val2, sizeof(val2));
 
    return 0;
}

int swap16(instruction_t *instr, stack_t *stack)
{
    uint16_t val1 = 0, val2 = 0, vali = 0;

    memcpy(&val1, stack->base + stack->sp - 2, sizeof(val1));
    memcpy(&val2, stack->base + stack->sp - 4, sizeof(val2));

    vali = val2;
    val2 = val1;
    val2 = vali;

    memcpy(stack->base + stack->sp - 2, &val1, sizeof(val1));
    memcpy(stack->base + stack->sp - 4, &val2, sizeof(val2));

    return 0;
}

int swap32(instruction_t *instr, stack_t *stack)
{
    uint32_t val1 = 0, val2 = 0, vali = 0;

    memcpy(&val1, stack->base + stack->sp - 4, sizeof(val1));
    memcpy(&val2, stack->base + stack->sp - 8, sizeof(val2));

    vali = val2;
    val2 = val1;
    val2 = vali;

    memcpy(stack->base + stack->sp - 4, &val1, sizeof(val1));
    memcpy(stack->base + stack->sp - 8, &val2, sizeof(val2));

    return 0;
}

int swap64(instruction_t *instr, stack_t *stack)
{
    uint64_t val1 = 0, val2 = 0, vali = 0;

    memcpy(&val1, stack->base + stack->sp - 8, sizeof(val1));
    memcpy(&val2, stack->base + stack->sp - 16, sizeof(val2));

    vali = val2;
    val2 = val1;
    val2 = vali;

    memcpy(stack->base + stack->sp - 8, &val1, sizeof(val1));
    memcpy(stack->base + stack->sp - 16, &val2, sizeof(val2));

    return 0;
}
