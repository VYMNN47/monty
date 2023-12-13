#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next) {
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->n + (*stack)->next->n;
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	free(temp);
}
