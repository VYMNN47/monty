#include "monty.h"

/**
 * push - Adds a new node with a given value to the stack
 * @stack: Pointer to the head of the stack
 * @line_num: Line number in the Monty file
 *
 * Return: Void
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node;
	int value;

	if (info.arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	value = _atoi(info.arg);

	if (value < 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = *stack;
	*stack = new_node;
}

/**
 * pall - Prints all elements in the stack
 * @stack: Pointer to the head of the stack
 * @line_num: Line number in the Monty file
 *
 * Return: Void
 */

void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *node = *stack;

	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}

	(void)line_num;
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file being processed.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - Removes the top element of the stack.
 *
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file being processed.
 *
 * Return: No return value.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		stack_t *tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * swap - Swaps the top two elements of the stack.
 *
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file being processed.
 *
 * Return: No return value.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int num;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num;
}
















