#include "monty.h"
/**
 * f_mul - multiplies the first 2 elem of the stack.
 * @stack: struct_t stack.
 * @line_number: number of line.
 * Return: void.
 */
void f_mul(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp1;

    if (stackt_len(*stack) < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_doubly(*stack);
		exit(EXIT_FAILURE);
    }
    tmp1 = (*stack)->next;
    tmp1->n *= (*stack)->n;
    f_pop(stack, line_number);
}
/**
 * f_mod - calculats and save the module of 1st 2 elem of stack.
 * @stack: struct_t stack.
 * @line_number: number of line.
 * Return: void.
 */
void f_mod(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp1;

    if (stackt_len(*stack) < 2)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_doubly(*stack);
		exit(EXIT_FAILURE);
    }
    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
		free_doubly(*stack);
		exit(EXIT_FAILURE);
    }
    tmp1 = (*stack)->next;
    tmp1->n %= (*stack)->n;
    f_pop(stack, line_number);
}