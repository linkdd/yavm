#include <yavm/stack.h>

void stack_resize(stack_t *stack)
{
    if (stack != NULL && stack->base != NULL)
    {
        int8_t *newbase = realloc(stack->base, stack->size + YAVM_MIN_STACK_SIZE);

        if (newbase != NULL)
        {
            stack->size += YAVM_MIN_STACK_SIZE;
            stack->base = newbase;
        }
    }
}
