#include "monty.h"
/**
 * get_line - into the while.
 * @alen: number of argument.
 * @line_n: arguments.
 * @head: stack;
 * @stream: open file.
 * Return: 0.
 */
int number = 0;
int get_line(size_t ln, unsigned int l_n, char *l, stack_t *h, FILE *s)
{
	ssize_t nread;
	char *token, *token2;

	while ((nread = getline(&l, &ln, s)) != -1)
	{
		token = strtok(l, " \n\t");
		l_n++;
		if (token == NULL)
			continue;
		token2 = strtok(NULL, " \n\t");
		if (token2 != NULL)
		{
			if (check_number(token2) == 1)
			{
				fprintf(stderr, "L%d: usage: push integer\n", l_n);
				free(l);
				free_doubly(h);
				exit(EXIT_FAILURE);
			}
			number = atoi(token2);
		}
		if (search_opcode(token, l_n, &h) == 1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", l_n, token);
			free(token);
			free_doubly(h);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
