#include "monty.h"

void exec(stack_t **stack, unsigned int line_num)
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
		i++;
	}
	if (opc[i].opcode == NULL && info.op)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, info.op);
		exit(EXIT_FAILURE);
	}
}
