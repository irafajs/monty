#include "monty.h"

/**
 * process_command - procees the command
 * @stack: passed arg as a pointer to the node
 * @line: passed argument which hold the mont instruction
 * @line_num: passed argumenr as a line of the instruction
 */
void process_command(stack_t **stack, char *line, int line_num)
{
	char opcode[MAX_LINE_LENGTH];
	int argument;
	int num_tokens = sscanf(line, "%s %d", opcode, &argument);

	if (num_tokens == 1 && strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_num);
	}
	else if (num_tokens == 2 && strcmp(opcode, "push") == 0)
	{
		push(stack, argument, line_num);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, line);
		exit(EXIT_FAILURE);
	}
}
