#include <yavm/instruction.h>
#include <string.h>

int dec8(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint8_t val = 0, result = 0;

    if (instr->has_operand)
    {
        memcpy(&val, (uint8_t*) instr + 1, sizeof(val));
        bytes = 1;
    }
    else
    {
        stack->sp -= 1;
        memcpy(&val, stack->base + stack->sp, sizeof(val));
    }

    result = val - 1;

    memcpy(stack->base + stack->sp, &result, sizeof(result));
    stack->sp += 1;

    return bytes;
}

int dec16(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint16_t val = 0, result = 0;

    if (instr->has_operand)
    {
        memcpy(&val, (uint8_t*) instr + 1, sizeof(val));
        bytes = 2;
    }
    else
    {
        stack->sp -= 2;
        memcpy(&val, stack->base + stack->sp, sizeof(val));
    }

    result = val - 1;

    memcpy(stack->base + stack->sp, &result, sizeof(result));
    stack->sp += 2;

    return bytes;
}

int dec32(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint32_t val = 0, result = 0;

    if (instr->has_operand)
    {
        memcpy(&val, (uint8_t*) instr + 1, sizeof(val));
        bytes = 4;
    }
    else
    {
        stack->sp -= 4;
        memcpy(&val, stack->base + stack->sp, sizeof(val));
    }

    result = val - 1;

    memcpy(stack->base + stack->sp, &result, sizeof(result));
    stack->sp += 4;

    return bytes;
}

int dec64(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint64_t val = 0, result = 0;

    if (instr->has_operand)
    {
        memcpy(&val, (uint8_t*) instr + 1, sizeof(val));
        bytes = 8;
    }
    else
    {
        stack->sp -= 8;
        memcpy(&val, stack->base + stack->sp, sizeof(val));
    }

    result = val - 1;

    memcpy(stack->base + stack->sp, &result, sizeof(result));
    stack->sp += 8;

    return bytes;
}
