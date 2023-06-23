#include "monty.h"

/**
 * monty_pint - Print the top value of the stack.
 *
 * @stack: Pointer to the stack list.
 * @line_number: Current line number in the Monty bytecodes file.
 * Return: Nothing.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (!top)
	{
		f_errors(1, line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", top->n);
}

/**
 * monty_pop - Remove the top value from the stack.
 *
 * @stack: Pointer to the stack_t list.
 * @line_number: Line number in the Monty bytecodes file.
 * Return: Nothing.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (!top)
	{
		f_errors(2, line_number);
		exit(EXIT_FAILURE);
	}

	if (top->next)
		top->next->prev = top->prev;
	*stack = top->next;
	free(top);
}

/**
 * monty_swap - Swap the two values at the top of the stack.
 *
 * @stack: Pointer to the top of the stack list.
 * @line_number: Line number in the Monty bytecodes file.
 * Return: Nothing.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(3, line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = temp;
}

/**
 * monty_add - Add the two top values of the stack.
 *
 * @stack: Pointer to the stack list.
 * @line_number: Line number in the Monty bytecodes file.
 * Return: Nothing.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(4, line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = result;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - Subtract the second value from the top of the stack
 * linked by the top value.
 *
 * @stack: Pointer to the stack list.
 * @line_number: Line number in the Monty bytecodes
 * Return: Nothing.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(5, line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;
	monty_pop(stack, line_number);
}
