#include "monty.h"

/**
 * mod - divides second top element of the stack by top element of the stack
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the monty source file.
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n % (*stack)->n;
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	free(temp);
}

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (!temp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", temp->n);
}

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num;

	(void)line_number;

	while (temp)
	{
		num = temp->n;
		if (num == 0 || (num < 0 && num > 127))
			break;
		putchar(num);
		temp = temp->next;
	}
        printf("\n");
}
