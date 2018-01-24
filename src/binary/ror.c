#include <yavm/instruction.h>
#include <string.h>

int rol8(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint8_t val = 0, shifted, rot_bits, result = 0;
    uint8_t bits = 0;

    if (instr->has_operand)
    {
        memcpy(&val,  (uint8_t*) instr + 1, sizeof(val));
        memcpy(&bits, (uint8_t*) instr + 2, sizeof(bits));
        bytes = 2;
    }
    else
    {
        stack->sp -= 1;
        memcpy(&val, stack->base + stack->sp, sizeof(val));

        stack->sp -= 1;
        memcpy(&bits, stack->base + stack->sp, sizeof(bits));
    }

    shifted = val >> bits;
    rot_bits = val << (8 - bits);
    result = shifted | rot_bits;

    memcpy(stack->base + stack->sp, &result, sizeof(result));
    stack->sp += 1;

    return bytes;
}

int rol16(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint16_t val = 0, shifted, rot_bits, result = 0;
    uint8_t bits = 0;

    if (instr->has_operand)
    {
        memcpy(&val,  (uint8_t*) instr + 1, sizeof(val));
        memcpy(&bits, (uint8_t*) instr + 3, sizeof(bits));
        bytes = 3;
    }
    else
    {
        stack->sp -= 2;
        memcpy(&val, stack->base + stack->sp, sizeof(val));

        stack->sp -= 1;
        memcpy(&bits, stack->base + stack->sp, sizeof(bits));
    }

    shifted = val >> bits;
    rot_bits = val << (16 - bits);
    result = shifted | rot_bits;

    memcpy(stack->base + stack->sp, &result, sizeof(result));
    stack->sp += 2;

    return bytes;
}

int rol32(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint32_t val = 0, shifted, rot_bits, result = 0;
    uint8_t bits = 0;

    if (instr->has_operand)
    {
        memcpy(&val,  (uint8_t*) instr + 1, sizeof(val));
        memcpy(&bits, (uint8_t*) instr + 5, sizeof(bits));
        bytes = 5;
    }
    else
    {
        stack->sp -= 4;
        memcpy(&val, stack->base + stack->sp, sizeof(val));

        stack->sp -= 1;
        memcpy(&bits, stack->base + stack->sp, sizeof(bits));
    }

    shifted = val >> bits;
    rot_bits = val << (32 - bits);
    result = shifted | rot_bits;

    memcpy(stack->base + stack->sp, &result, sizeof(result));
    stack->sp += 4;

    return bytes;
}

int rol64(instruction_t *instr, stack_t *stack)
{
    int bytes = 0;
    uint64_t val = 0, shifted, rot_bits, result = 0;
    uint8_t bits = 0;

    if (instr->has_operand)
    {
        memcpy(&val,  (uint8_t*) instr + 1, sizeof(val));
        memcpy(&bits, (uint8_t*) instr + 9, sizeof(bits));
        bytes = 9;
    }
    else
    {
        stack->sp -= 8;
        memcpy(&val, stack->base + stack->sp, sizeof(val));

        stack->sp -= 1;
        memcpy(&bits, stack->base + stack->sp, sizeof(bits));
    }

    shifted = val >> bits;
    rot_bits = val << (64 - bits);
    result = shifted | rot_bits;

    memcpy(stack->base + stack->sp, &result, sizeof(result));
    stack->sp += 8;

    return bytes;
}
