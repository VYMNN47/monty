#include "monty.h"

info_t info = {NULL, 0};

int main(int argc, char **argv)
{
	FILE *filem;
	char *buff = NULL;
	size_t buff_len = 0;
	unsigned int line_num = 1;
	stack_t *stack = NULL;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filem = fopen(argv[1], "r");
	if (!filem || !argv[1])
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}


	while ((getline(&buff, &buff_len, filem)) != -1)
	{
		if (*buff == '\n')
		{
			line_num++;
			continue;
		}

		info.op = strtok(buff, " \t\n");
		if (!info.op || *info.op == '#')
		{
			line_num++;
			continue;
		}
		info.arg = strtok(NULL, " \t\n");
		exec(&stack, line_num);
		line_num++;
	}
	free(buff);
	free_stack(stack);
	fclose(filem);
	exit(EXIT_SUCCESS);
}
