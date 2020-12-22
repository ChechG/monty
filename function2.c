#include "monty.h"
/**
 * search_opcode - searches for opcode function.
 * @token: supposed opcode name.
 * @line_n: number of line.
 * @head: struct for opcodes.
 * Return: 0.
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
    int i, temp1, temp2;
    stack_t *tmp1 = (*stack), *tmp2 = (*stack);

    for (i = 1; tmp1->next != NULL; i++)
        tmp1 = tmp1->next;
    if (i < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_doubly(*stack);
		exit(EXIT_FAILURE);
    }
    temp1 = tmp2->n;
    temp2 = (tmp2->next)->n;
    tmp2->n = temp2;
    (tmp2->next)->n = temp1;
    (*stack) = tmp2;
}