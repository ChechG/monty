#include "monty.h"
/**
 * get_line - into the while.
 * @alen: number of argument.
 * @line_n: arguments.
 * @head: stack;
 * @stream: open file.
 * Return: void.
 */
int number = 0;
void get_line(size_t ln, unsigned int l_n, char *l, stack_t *h, FILE *s)
{
	ssize_t nread;
	char *token, *token2;

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		token = strtok(line, " \n\t");
		line_n++;
		if (token == NULL)
			continue;
		token2 = strtok(NULL, " \n\t");
		if (token2 != NULL)
		{
			if (check_number(token2) == 1)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_n);
				free(line);
				free_doubly(head);
				exit(EXIT_FAILURE);
			}
			number = atoi(token2);
		}
		if (search_opcode(token, line_n, &head) == 1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, token);
			free(token);
			free_doubly(head);
			exit(EXIT_FAILURE);
		}
	}
}
