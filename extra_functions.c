#include "monty.h"

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

int _atoi(const char *str)
{
    int result = 0;
    int sign = 1;

    while (*str == ' ' || *str == '\t' || *str == '\n')
        str++;

    if (*str == '+' || *str == '-') {
        sign = (*str++ == '+') ? 1 : -1;
    }

    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    if (*str != '\0' && (*str < '0' || *str > '9')) {
        return -1;
    }

    return sign * result;
}
