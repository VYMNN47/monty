#include "monty.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: current head node
 * @str: string to be duplicated
 * Return: returns new element or NULL if failure
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
	value = atoi(info.arg);

	if (!value)
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
 * free_list -  a function that frees a list_t list
 * @head: head of the linked list
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	if (!stack)
		return;

	while ((temp = stack) != NULL)
	{
		stack = stack->next;
		free(temp);
	}
}
