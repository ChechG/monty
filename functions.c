#include "monty.h"

int search_opcode(char *token, unsigned int line_n, stack_t *head)
{
	instruction_t options[] = {
		{"pall", f_pall},
		{"push", f_push},
		{NULL, NULL}
	};
	int i = 0;

	while(options[i].opcode != NULL)
	{
		printf("opcode y token: %s y %s\n",options[i].opcode, token);
		if (strcmp(options[i].opcode, token) == 0)
		{
			printf("encontro coincidencia en :%s y %s\n",options[i].opcode, token);
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
	printf("es un push\n");
}
void f_pall(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	printf("es un pall\n");
}
