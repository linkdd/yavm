#include <yavm/vm.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *fin = NULL;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if ((fin = fopen(argv[1], "rb")) != NULL)
    {
        int retcode = EXIT_SUCCESS;

        vm_t *vm = vm_new();
        vm_load(vm, program_new_from_file(fin));
        fclose(fin);

        while (!vm_halted(vm, &retcode))
        {
            vm_step(vm);
        }

        vm_delete(vm);
        return retcode;
    }

    return EXIT_FAILURE;
}
