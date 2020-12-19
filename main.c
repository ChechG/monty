#include "monty.h"

int main(int ac, char **av)
{
    instruction_t opc[] = {
        {"push", fpush},
        {"pall", fpall},
        {"pint", fpint},
        {"pop", fpop},
        {"swap", fswap},
        {"add", fadd},
        {NULL, NULL}
    };
    
}