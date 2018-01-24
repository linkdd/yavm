#include <yavm/instruction.h>
#include <string.h>

int pop8(instruction_t *instr, stack_t *stack)
{
    if (stack->sp >= 1)
    {
        stack->sp -= 1;
    }
    else
    {
        stack->sp = 0;
    }

    return 0;
}

int pop16(instruction_t *instr, stack_t *stack)
{
    if (stack->sp >= 2)
    {
        stack->sp -= 2;
    }
    else
    {
        stack->sp = 0;
    }

    return 0;
}

int pop32(instruction_t *instr, stack_t *stack)
{
    if (stack->sp >= 4)
    {
        stack->sp -= 4;
    }
    else
    {
        stack->sp = 0;
    }

    return 0;
}

int pop64(instruction_t *instr, stack_t *stack)
{
    if (stack->sp >= 8)
    {
        stack->sp -= 8;
    }
    else
    {
        stack->sp = 0;
    }

    return 0;
}
