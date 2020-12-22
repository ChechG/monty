#include "monty.h"
/**
 * check_number - checks if string is a number.
 * @token: holds string that could be a number.
 * Return: 0 or 1.
 */
int check_number(char *token)
{
	int i;

	for (i = 0; token[i] != '\0'; i++)
	{
		if (token[i] == '-')
			continue;
		if (token[i] < 48 || token[i] > 57)
			return (1);
	}
	return (0);
}

/**
 * stackt_len - returns the elements of the array.
 * @h: struct listint_t from main.
 * Return: number of nodes.
 */
size_t stackt_len(stack_t *h)
{
	int elements;

	elements = 0;
	if (h == NULL)
	{
		return (0);
	}
	while (h != NULL)
	{
		h = h->next;
		elements++;
	}
	return (elements);
}
