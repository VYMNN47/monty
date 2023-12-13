#include "monty.h"

/**
 * exec - handles the execution of the opcodes
 * @stack: the given stack
 * @line_num: number of the line within the monty file
 */

void exec(stack_t **stack, unsigned int line_num)
{
	unsigned int i = 0;
	instruction_t opc[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"NULL", NULL}
	};
	while (opc[i].opcode)
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
