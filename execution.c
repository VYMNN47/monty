#include "monty.h"

/**
 * exec - handles the execution of the opcode
 * @stack: A double pointer to the top of the stack.
 * @line_num: The line number in the monty source file.
 */

void exec(stack_t **stack, unsigned int line_num)
{
	unsigned int i = 0;
	instruction_t opc[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
		{"div", _div}, {"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr}, {NULL, NULL}
/*		{"queue", queue}, {"stack", stack}, {NULL, NULL} */
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
