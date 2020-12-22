#include "monty.h"
/**
 * f_swap - swaps first to num of stack.
 * @stack: struct_t stack.
 * @line_number: number of line.
 * Return: void.
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
/**
 * f_add - adds the first 2 elem of the stack.
 * @stack: struct_t stack.
 * @line_number: number of line.
 * Return: void.
 */
void f_add(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp1;

    if (stackt_len(*stack) < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_doubly(*stack);
		exit(EXIT_FAILURE);
    }
    tmp1 = (*stack)->next;
    tmp1->n += (*stack)->n;
    f_pop(stack, line_number);
}
/**
 * f_nop - does absolutely nothing.
 * @stack: struct_t stack.
 * @line_number: number of line.
 * Return: void.
 */
void f_nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}