#include "monty.h"
int number = 0;
/**
 * main - point of entry.
 * @argc: number of argument.
 * @argv: arguments.
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	FILE *stream;
	size_t len = 0;
	unsigned int line_n = 0;
	char *line = NULL, *token, *token2;
	ssize_t nread;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		token = strtok(line, " \n\t");
		line_n++;
		if (token == NULL)
			continue;
		if (token[0] == '#')
			continue;
		token2 = strtok(NULL, " \n\t");
		if (strcmp(token, "push") == 0 && token2 == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_n);
			free_doubly(head);
			exit(EXIT_FAILURE);
		}
		if (token2 != NULL)
		{
			if (check_number(token2) == 1)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_n);
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
	free(line);
	free_doubly(head);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
