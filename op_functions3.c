#include "monty.h"

/**
 * pushq - Pushes an element onto a stack
 * @stack: A pointer to the stack.
 * @line_num: The line number associated with the pushq operation.
 *
 */

void pushq(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node, *temp;
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
    	temp = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
	  	exit(EXIT_FAILURE);
	}
	new_node->n = value, new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}

void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	info.format = 1;
}

void stack_l(stack_t **stack, unsigned int line_number)
{
        (void)stack;
        (void)line_number;
        info.format = 0;
}
