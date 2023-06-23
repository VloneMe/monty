#include "monty.h"

/**
 * monty_rotl - Rotate the stack to the top
 *
 * @stack: Pointer to the stack
 * @line_number: Line number of a Monty bytecodes file
 * Return: Nothing.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *current = *stack;

	if (*stack)
	{
		temp = current->n;
		while (current->next != NULL)
		{
			current->n = current->next->n;
			current = current->next;
		}
		current->n = temp;
	}
	(void)line_number;
}

/**
 * monty_rotr - Rotate the stack to the bottom
 *
 * @stack: Pointer to the stack
 * @line_number: Line number of a Monty bytecodes file
 * Return: Nothing.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *current = *stack;

	if (*stack)
	{
		while (current->next != NULL)
			current = current->next;

		temp = current->n;
		while (current->prev != NULL)
		{
			current->n = current->prev->n;
			current = current->prev;
		}
		current->n = temp;
	}
	(void)line_number;
}
