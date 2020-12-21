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
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_n = 0;
	char *token;
	char *token2;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file\n", argv[0]);
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
		token2 = strtok(NULL, " \n\t");
		if (token2 != NULL)
			number = atoi(token2);
		search_opcode(token, line_n, &head);
	}
	free(line);
	free_doubly(head);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
