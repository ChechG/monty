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
		if (token[i] < 48 || token[i] > 57)
			return (1);
	}
	return (0);
}
