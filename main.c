#include "monty.h"

info_t info = {NULL, 0};

/**
 * main - Entry point for executing Monty bytecode
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char **argv)
{
	FILE *filem;
	char *buff = NULL;
	size_t buff_len = 0;
	unsigned int line_num = 1;
	ssize_t read_line = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	}
	filem = fopen(argv[1], "r");
	if (!filem || !argv[1])
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		fclose(filem);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		read_line = getline(&buff, &buff_len, filem);
		if (*buff == '\n')
		{
			line_num++;
			continue;
		}
		info.op = strtok(buff, " \t\n");
		if (!info.op || (info.op && *info.op == '#'))
		{
			line_num++;
			continue;
		}
		info.arg = strtok(NULL, " \t\n");
		if (read_line > 0)
			exec(&stack, line_num);
		line_num++;
	}
	free(buff);
	free_stack(stack);
	fclose(filem);
	exit(EXIT_SUCCESS);
}
