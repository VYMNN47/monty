#include "monty.h"

int flag = 0;

void exec(stack_t **stack, unsigned int line_num, char *buff, FILE *filem)
{
	unsigned int i = 0;
	instruction_t opc[] =
	{
		{"push", push}, {"pall", pall}, {NULL, NULL}
	};

	while(opc[i].opcode)
	{
		if (strcmp(info.op, opc[i].opcode) == 0)
		{
			opc[i].f(stack, line_num);
			return;
		}
		if (flag)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			fclose(filem);
			free(buff);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (opc[i].opcode == NULL && info.op)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, info.op);
		fclose(filem);
		free(buff);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
