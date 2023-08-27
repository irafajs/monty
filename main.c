#include "monty.h"
void escapeb(void);
stack_t *stack = NULL;
/**
 * main - entry point
 * @argc: passed argument as a counter to the command line
 * @argv: passed arg as a vector of command on CLI
 *
 * Return: return 0 at success
 */
int main(int argc, char *argv[])
{
	char *filename = argv[1];
	FILE *file;
	char line[MAX_LINE_LENGTH];
	int line_num = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (line[strlen(line) - 1] == '\n')
		{
			line[strlen(line) - 1] = '\0';
		}
		process_command(&stack, line, line_num);
		line_num++;
	}
	fclose(file);
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
	return (EXIT_SUCCESS);
}
