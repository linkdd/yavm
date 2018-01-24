#include <yavm/instruction.h>
#include <string.h>

int push8(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint8_t val = 0;

    if (instr->has_operand)
    {
        memcpy(&val, (uint8_t*) instr + 1, sizeof(val));
        bytes = 1;
    }
    else
    {
        memcpy(&val, stack->base + stack->sp, sizeof(val));
    }

    memcpy(stack->base + stack->sp, &val, sizeof(val));
    stack->sp += 1;

    return bytes;
}

int push16(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint16_t val = 0;

    if (instr->has_operand)
    {
        memcpy(&val, (uint8_t*) instr + 1, sizeof(val));
        bytes = 2;
    }
    else
    {
        memcpy(&val, stack->base + stack->sp, sizeof(val));
    }


    memcpy(stack->base + stack->sp, &val, sizeof(val));
    stack->sp += 2;

    return bytes;
}

int push32(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint32_t val = 0;

    if (instr->has_operand)
    {
        memcpy(&val, (uint8_t*) instr + 1, sizeof(val));
        bytes = 4;
    }
    else
    {
        memcpy(&val, stack->base + stack->sp, sizeof(val));
    }

    memcpy(stack->base + stack->sp, &val, sizeof(val));
    stack->sp += 4;

    return bytes;
}

int push64(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint64_t val = 0;

    if (instr->has_operand)
    {
        memcpy(&val, (uint8_t*) instr + 1, sizeof(val));
        bytes = 8;
    }
    else
    {
        memcpy(&val, stack->base + stack->sp, sizeof(val));
    }

    memcpy(stack->base + stack->sp, &val, sizeof(val));
    stack->sp += 8;

    return bytes;
}
