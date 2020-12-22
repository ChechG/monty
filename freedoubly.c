#include "monty.h"
/**
 * free_doubly - frees a double list.
 * @head: doubly linked list.
 * Return: void.
 */
void free_doubly(stack_t *head)
{
	stack_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
	free(head);
}
