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
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{NULL, NULL}
	};
	int i = 0;

	while (options[i].opcode)
	{
		if (strcmp(options[i].opcode, token) == 0)
		{
			options[i].f(head, line_n);
			return (0);
		}
		i++;
	}
	return (1);
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
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_doubly(*stack);
		exit(EXIT_FAILURE);
	}
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
	stack_t *new = (*stack);

	(void)line_number;
	if (stack == NULL)
	{
		free_doubly(*stack);
		exit(EXIT_FAILURE);
	}
	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
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
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_doubly(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack) != NULL)
		printf("%d\n", (*stack)->n);
}

/**
 * f_pop - deletes first element of stack.
 * @stack: struct_t stack.
 * @line_number: number of line.
 * Return: void.
 */
 void f_pop(stack_t **stack, unsigned int line_number)
 {
	stack_t *nodo = (*stack);

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	free(nodo);
 }