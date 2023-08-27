#include "monty.h"

/**
 * pchar - Print the char at the top of the stack
 * @stack: Pointer to the stack head
 * @conut: Line number of the instruction
 *
 * Description: Treats the integer at the top of the stack as an ASCII value
 * and prints the corresponding character followed by a new line
 * Return: No return value
 */
void pchar(stack_t **stack, unsigned int count)
{
	int ascii_value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		exit(EXIT_FAILURE);
	}

	ascii_value = (*stack)->n;
	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		exit(EXIT_FAILURE);
	}

	putchar(ascii_value);
	putchar('\n');
}
