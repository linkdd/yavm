#include <yavm/instruction.h>
#include <string.h>

int pow8(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint8_t val1 = 0, val2 = 0, result = 1;

    if (instr->has_operand)
    {
        memcpy(&val1, (uint8_t*) instr + 1, sizeof(val1));
        memcpy(&val2, (uint8_t*) instr + 2, sizeof(val2));
        bytes = 2;
    }
    else
    {
        stack->sp -= 1;
        memcpy(&val1, stack->base + stack->sp, sizeof(val1));

        stack->sp -= 1;
        memcpy(&val2, stack->base + stack->sp, sizeof(val2));
    }

    for (; val2 > 0; val2--)
    {
        result *= val1;
    }

    memcpy(stack->base + stack->sp, &result, sizeof(result));
    stack->sp += 1;

    return bytes;
}

int pow16(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint16_t val1 = 0, val2 = 0, result = 1;

    if (instr->has_operand)
    {
        memcpy(&val1, (uint8_t*) instr + 1, sizeof(val1));
        memcpy(&val2, (uint8_t*) instr + 3, sizeof(val2));
        bytes = 4;
    }
    else
    {
        stack->sp -= 2;
        memcpy(&val1, stack->base + stack->sp, sizeof(val1));

        stack->sp -= 2;
        memcpy(&val2, stack->base + stack->sp, sizeof(val2));
    }

    for (; val2 > 0; val2--)
    {
        result *= val1;
    }

    memcpy(stack->base + stack->sp, &result, sizeof(result));
    stack->sp += 2;

    return bytes;
}

int pow32(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint32_t val1 = 0, val2 = 0, result = 1;

    if (instr->has_operand)
    {
        memcpy(&val1, (uint8_t*) instr + 1, sizeof(val1));
        memcpy(&val2, (uint8_t*) instr + 5, sizeof(val2));
        bytes = 8;
    }
    else
    {
        stack->sp -= 4;
        memcpy(&val1, stack->base + stack->sp, sizeof(val1));

        stack->sp -= 4;
        memcpy(&val2, stack->base + stack->sp, sizeof(val2));
    }

    for (; val2 > 0; val2--)
    {
        result *= val1;
    }

    memcpy(stack->base + stack->sp, &result, sizeof(result));
    stack->sp += 4;

    return bytes;
}

int pow64(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint64_t val1 = 0, val2 = 0, result = 1;

    if (instr->has_operand)
    {
        memcpy(&val1, (uint8_t*) instr + 1, sizeof(val1));
        memcpy(&val2, (uint8_t*) instr + 9, sizeof(val2));
        bytes = 16;
    }
    else
    {
        stack->sp -= 8;
        memcpy(&val1, stack->base + stack->sp, sizeof(val1));

        stack->sp -= 8;
        memcpy(&val2, stack->base + stack->sp, sizeof(val2));
    }

    for (; val2 > 0; val2--)
    {
        result *= val1;
    }

    memcpy(stack->base + stack->sp, &result, sizeof(result));
    stack->sp += 8;

    return bytes;
}
