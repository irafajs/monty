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
	char argument[MAX_LINE_LENGTH];
	int is_int = 1;
	int value, i;
	int num_tokens = sscanf(line, "%s %s", opcode, argument);

	if (num_tokens == 1 && strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_num);
	}
	else if (num_tokens == 2 && strcmp(opcode, "push") == 0)
	{
		for (i = 0; argument[i] != '\0'; i++)
		{
			if (!isdigit(argument[i]) && (i == 0 && argument[i] != '-'))
			{
				is_int = 0;
				break;
			}
		}
		if (!is_int)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
		value = atoi(argument);
		push(stack, value, line_num);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, line);
		exit(EXIT_FAILURE);
	}
}
