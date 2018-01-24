#include <yavm/vm.h>
#include <string.h>

vm_t *vm_new (void)
{
    vm_t *vm = calloc(1, sizeof(vm_t));

    if (vm != NULL)
    {
        vm->prog.code = NULL;
        vm->prog.size = 0;
        vm->prog.ip = 0;

        vm->stack.base = calloc(YAVM_MIN_STACK_SIZE, sizeof(uint8_t));
        vm->stack.size = YAVM_MIN_STACK_SIZE;
        vm->stack.sp = 0;

        if (vm->stack.base == NULL)
        {
            vm_delete(vm);
            return NULL;
        }

        vm->halted = true;
        vm->retcode = 0;
    }

    return vm;
}

void vm_delete(vm_t *vm)
{
    if (vm != NULL)
    {
        if (vm->prog.code != NULL)
        {
            free(vm->prog.code);
        }

        if (vm->stack.base != NULL)
        {
            free(vm->stack.base);
        }

        free(vm);
    }
}

void vm_load(vm_t *vm, program_t *prog)
{
    if (vm != NULL && prog != NULL)
    {
        vm->prog.code = calloc(prog->size, sizeof(instruction_t));

        if (vm->prog.code != NULL)
        {
            vm->prog.size = prog->size;
            vm->prog.ip = 0;
            vm->halted = false;
        }
    }
}

void vm_step(vm_t *vm)
{
    if (vm != NULL && !vm_halted(vm, NULL))
    {
        if (vm->prog.ip == vm->prog.size)
        {
            vm->halted = true;
        }
        else
        {
            int bytes = 1;

            /* is there enough space for a 64bits value ? */ 
            if (vm->stack.sp >= (vm->stack.size - 8))
            {
                stack_resize(&(vm->stack));
            }

            instruction_t *instr = vm->prog.code + vm->prog.ip;
            bytes += do_instruction(instr, &(vm->stack));
            vm->prog.ip += bytes;
    }
}

bool vm_halted(vm_t *vm, int *retcode)
{
    if (vm != NULL)
    {
        if (retcode != NULL)
        {
            *retcode = vm->retcode;
        }

        return vm->halted;
    }

    return true;
}

program_t *program_new_from_file(FILE *fin)
{
    program_t *prog = NULL;
    uint8_t *mem = NULL;
    size_t sz = 0;

    fseek(fin, 0, SEEK_END);
    sz = ftell(fin);
    rewing(fin);

    mem = calloc(sz, sizeof(instruction_t));

    if (mem != NULL)
    {
        fread(mem, sizeof(instruction_t), sz, fin);
        prog = program_new_from_memory(mem, sz);
        free(mem);
    }

    return prog;
}

program_t *program_new_from_memory(uint8_t *mem, size_t size)
{
    program_t *prog = calloc(1, sizeof(program_t));

    if (prog != NULL)
    {
        prog->code = calloc(size, sizeof(instruction_t));

        if (prog->code == NULL)
        {
            free(prog);
            return NULL;
        }

        memcpy(prog->code, mem, size);
        prog->size = size;
        prog->ip = 0;
    }

    return prog;
}
