#include "monty.h"

int check_number(char *token)
{
    int i;

    for (i = 0; token[i] != '\0'; i++)
    {
        if (token[i] < 48 || token[i] > 57)
            return (1);
    }
    return (0);
}