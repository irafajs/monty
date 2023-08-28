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
	int num_tokens = sscanf(line, "%s %s", opcode, argument);

	if (num_tokens == 1 && strcmp(opcode, "pall") == 0)
		pall(stack, line_num);
	else if (num_tokens == 1 && strcmp(opcode, "pint") == 0)
		pint(stack, line_num);
	else if (num_tokens == 1 && strcmp(opcode, "pop") == 0)
		pop_only(stack, argument, line_num);
	else if (num_tokens == 2 && strcmp(opcode, "push") == 0)
		only_p(stack, argument, line_num);
	else if (num_tokens == 1 && strcmp(opcode, "swap") == 0)
		swap(stack, line_num);
	else if (num_tokens == 1 && strcmp(opcode, "add") == 0)
		add(stack, line_num);
	else if (num_tokens == 1 && strcmp(opcode, "sub") == 0)
		sub(stack, line_num);
	else if (num_tokens == 1 && strcmp(opcode, "div") == 0)
		divide(stack, line_num);
	else if (num_tokens == 1 && strcmp(opcode, "mul") == 0)
		multiply(stack, line_num);
	else if (num_tokens == 1 && strcmp(opcode, "mod") == 0)
		modulo(stack, line_num);
	else if (num_tokens == 1 && strcmp(opcode, "pchar") == 0)
		pchar(stack, line_num);
	else if (num_tokens == 1 && strcmp(opcode, "pstr") == 0)
		pstr(stack, line_num);
	else if (num_tokens == 1 && strcmp(opcode, "rotl") == 0)
		rotl(stack, line_num);
	else if (num_tokens == 1 && strcmp(opcode, "rotr") == 0)
		rotr(stack, line_num);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, line);
		exit(EXIT_FAILURE);
	}
}
/**
 * only_p - handles the command of push only
 * @stack: pointer to stack node
 * @line: pointer to line
 * @line_num: count the line of the file
 *
 * Return: nothing
 */
void only_p(stack_t **stack, char *line, int line_num)
{
	int is_int = 1;
	int value, i;
	char argument[MAX_LINE_LENGTH];

	strcpy(argument, line);
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
/**
 * pop_only - handles the command for pop only that task
 * @stack: passed argument as a pointer to node stack
 * @line: passed argument as pointer to line
 * @line_num: passed argument for line count of the file
 *
 * Return: nothing
 */
void pop_only(stack_t **stack, char *line, int line_num)
{
	(void) line;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		pop(stack, line_num);
	}
}
