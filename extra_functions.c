#include "monty.h"

/**
 * free_stack -  a function that frees a list_t list
 * @stack: A pointer to the top of the stack.
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

/**
 * _atoi - Converts a string to an integer.
 * @str: The input string to be converted.
 *
 * Return: The integer value converted from the input string.
 *         Returns -1 if the string contains non-digit characters.
 */

int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;

	if (*str == '+' || *str == '-')
	{
		sign = (*str++ == '+') ? 1 : -1;
	}

	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}

	if (*str != '\0' && (*str < '0' || *str > '9'))
	{
		return (-1);
	}

	return (sign * result);
}
