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
/**
 * f_pchar - converts num to ascii value.
 * @stack: struct_t stack.
 * @line_number: number of line.
 * Return: void.
 */
void f_pchar(stack_t **stack, unsigned int line_number)
{
    stack_t *new = (*stack);

	(void)line_number;
	if (stack == NULL)
	{
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_doubly(*stack);
		exit(EXIT_FAILURE);
	}
	while (new != NULL)
	{
        if ((new->n >= 65 && new->n <= 90) || (new->n >= 97 && new->n <= 122))
        {
            putchar(new->n);
            putchar(10);
            new = new->next;
        }
        else
        {
            fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		    free_doubly(*stack);
		    exit(EXIT_FAILURE);
        }
	}
}
