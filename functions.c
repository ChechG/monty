#include "monty.h"
/**
 * search_opcode - searches for opcode function.
 * @token: supposed opcode name.
 * @line_n: number of line.
 * @head: struct for opcodes.
 * Return: 0.
 */
int search_opcode(char *token, unsigned int line_n, stack_t **head)
{
	instruction_t options[] = {
		{"pall", f_pall},
		{"push", f_push},
		{"pint", f_pint},
		{NULL, NULL}
	};
	int i = 0;

	while (options[i].opcode != NULL)
	{
		if (strcmp(options[i].opcode, token) == 0)
			options[i].f(head, line_n);
		i++;
	}
	return (0);
}
/**
 * f_push - pushes an int n to stack.
 * @stack: struct_t stack.
 * @line_number: number of line.
 * Return: void.
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->n = number;
	new->next = (*stack);
	new->prev = NULL;
	if ((*stack) != NULL)
		(*stack)->prev = new;
	*stack = new;
}
/**
 * f_pall - prints all int n of stack.
 * @stack: struct_t stack.
 * @line_number: number of line.
 * Return: void.
 */
void f_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	while ((*stack) != NULL)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}
}
/**
 * f_pint - prints all int n of stack.
 * @stack: struct_t stack.
 * @line_number: number of line.
 * Return: void.
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if ((*stack) == NULL)
		exit(EXIT_FAILURE);
	if ((*stack) != NULL)
		printf("%d\n", (*stack)->n);
}
