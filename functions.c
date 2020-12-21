#include "monty.h"

int search_opcode(char *token, unsigned int line_n, stack_t **head)
{
	instruction_t options[] = {
		{"pall", f_pall},
		{"push", f_push},
		{NULL, NULL}
	};
	int i = 0;

	while(options[i].opcode != NULL)
	{
		if (strcmp(options[i].opcode, token) == 0)
		{
			options[i].f(head, line_n);
		}
		i++;
	}
	return (0);
}

void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	
	(void)line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->n = line_number;
	new->next = *stack;
	new->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
void f_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if ((*stack) == NULL)
	{
		exit(EXIT_SUCCESS);
	}
	while ((*stack) != NULL)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}
	exit(EXIT_SUCCESS);
}
