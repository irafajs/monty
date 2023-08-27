#include "monty.h"

/**
 * pstr - Prints the string starting at the top of
 * the stack, followed by a new line
 * @head: stack head
 * @count:Counts the line number
 * Return: no return value
*/
void pstr(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
