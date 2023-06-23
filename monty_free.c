#include "monty.h"

/**
 * free_stack - Free the memory allocated for the stack
 *
 * @stack: Pointer to the doubly linked list representation of a stack
 * Return: void
 */
void monty_free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *tmp = NULL;

	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}

	*stack = NULL;
}
