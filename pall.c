#include "monty.h"

/**
 * pall - print all data of the stack
 * @stack: passed argument as pointer to struct
 * @line_number: passed argument
 *
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
