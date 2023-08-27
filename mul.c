#include "monty.h"

/**
 * multiply - multiplies the second top element by the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the command
 *
 * Return: nothing
 */
void multiply(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

