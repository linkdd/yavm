#include <yavm/instruction.h>
#include <yavm/stack/instructions.h>
#include <yavm/binary/instructions.h>

static const ihandler_t handlers[NB_INSTRUCTIONS][4] = {
    /* STACK */
    {push8,   push16,   push32,   push64},
    {pop8,    pop16,    pop32,    pop64},
    {swap8,   swap16,   swap32,   swap64},
    {tuck8,   tuck16,   tuck32,   tuck64},
    /* BINARY */
    {xor8,    xor16,    xor32,    xor64},
    {or8,     or16,     or32,     or64},
    {nor8,    nor16,    nor32,    nor64},
    {and8,    and16,    and32,    and64},
    {nand8,   nand16,   nand32,   nand64},
    {not8,    not16,    not32,    not64},
    {lshift8, lshift16, lshift32, lshift64},
    {rshift8, rshift16, rshift32, rshift64},
    {rol8,    rol16,    rol32,    rol64},
    {ror8,    ror16,    ror32,    ror64}
};

int do_instruction(instruction_t *instr, stack_t *stack)
{
    ihandler_t handler = handlers[instr->opcode][instr->size];

    if (handler != NULL)
    {
        return handler(instr, stack);
    }

    return 0;
}
