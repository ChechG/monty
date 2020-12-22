#include "monty.h"

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
	char *line = NULL;
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
	get_line(len, line_n, line, head, stream);
	free(line);
	free_doubly(head);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
