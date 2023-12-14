#include "monty.h"


/**
 * add - Adds the top two elements of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the monty source file.
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->n + (*stack)->next->n;
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	free(temp);
}

/**
 * nop - Does nothing.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the monty source file.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts top element of stack from second top element of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the monty source file.
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n - (*stack)->n;
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	free(temp);
}

/**
 * _div - divides second top element of the stack by top element of the stack
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the monty source file.
 */


void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n / (*stack)->n;
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	free(temp);
}

/**
 * mul - multiplies second top element of the stack by top element of the stack
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the monty source file.
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n * (*stack)->n;
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	free(temp);
}
