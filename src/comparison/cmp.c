#include <yavm/instruction.h>
#include <string.h>

int cmp8(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint8_t val1 = 0, val2 = 0;
    int8_t result = 0;

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
    
    if (val1 < val2)
    {
        result = -1;
    }
    else if (val1 > val2)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    memcpy(stack->base + stack->sp, &result, sizeof(result));
    stack->sp += 1;

    return bytes;
}

int cmp16(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint16_t val1 = 0, val2 = 0;
    int8_t result = 0;

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
    
    if (val1 < val2)
    {
        result = -1;
    }
    else if (val1 > val2)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    memcpy(stack->base + stack->sp, &result, sizeof(result));
    stack->sp += 1;

    return bytes;
}

int cmp32(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint32_t val1 = 0, val2 = 0;
    int8_t result = 0;

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
    
    if (val1 < val2)
    {
        result = -1;
    }
    else if (val1 > val2)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    memcpy(stack->base + stack->sp, &result, sizeof(result));
    stack->sp += 1;

    return bytes;
}

int cmp64(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint64_t val1 = 0, val2 = 0;
    int8_t result = 0;

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
    
    if (val1 < val2)
    {
        result = -1;
    }
    else if (val1 > val2)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    memcpy(stack->base + stack->sp, &result, sizeof(result));
    stack->sp += 1;

    return bytes;
}
