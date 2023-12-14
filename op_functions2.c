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
	stack_t *temp;
	int num;

	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;

	while (temp)
	{
		num = temp->n;
		if (num <= 0 || num > 127)
			break;
		printf("%c", num);
		temp = temp->next;
	}
        printf("\n");
}

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *h;

	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	h = (*stack)->next;
	h->prev = NULL;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next= *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp;
	(*stack) = h;
}

void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *last, *secondLast = NULL;


    if (*stack == NULL || (*stack)->next == NULL)
    {
        return;
    }

    last = *stack;
    while (last->next != NULL)
    {
        secondLast = last;
        last = last->next;
    }

    secondLast->next = NULL;

    last->next = *stack;
    *stack = last;

    (void)line_number;
}
