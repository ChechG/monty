#include "monty.h"
/**
 * free_doubly - frees a double list.
 * @head: doubly linked list.
 * Return: void.
 */
void free_doubly(stack_t *head)
{
	stack_t *current = head;

	while (current != NULL)
	{
		head = current->next;
		free(current);
		current = head;
	}
	head = NULL;
}