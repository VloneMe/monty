#include "monty.h"

/**
 * monty_mul - Multiply the two top values of the stack.
 * @stack: Pointer to the stack list.
 * @line_number: Line number in the Monty bytecodes file.
 * Return: Nothing.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(8, line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = result;
	monty_pop(stack, line_number);
}

/**
 * monty_div - Divide the second value from the top of the stack.
 *
 * @stack: Pointer to the stack list.
 * @line_number: Line number in the Monty bytecodes file.
 * Return: Nothing.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(6, line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		f_errors(7, line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = result;
	monty_pop(stack, line_number);
}

/**
 * monty_mod - Calculate the modulus of the second value from the top..
 *
 * @stack: Pointer to the stack list.
 * @line_number: Line number in the Monty bytecodes file.
 * Return: Nothing.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(9, line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		f_errors(7, line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = result;
	monty_pop(stack, line_number);
}

/**
 * monty_pchar - Print the character at the top value of the stack.
 *
 * @stack: Pointer to the stack list.
 * @line_number: Current line number in the Monty bytecodes file.
 * Return: Nothing.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	int value = 0;
	stack_t *top = *stack;

	if (!top)
	{
		f_errors(11, line_number);
		exit(EXIT_FAILURE);
	}

	value = top->n;
	if (value < 0 || value > 127)
	{
		f_errors(10, line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", top->n);
}

/**
 * monty_pstr - Print the string starting at the top of the stack..
 *
 * @stack: Pointer to the stack list.
 * @line_number: Current line number in the Monty bytecodes file.
 * Return: Nothing.
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	while (top != NULL)
	{
		if (top->n > 0 && top->n <= 127)
		{
			printf("%c", top->n);
			top = top->next;
		}
		else
			break;
	}

	printf("\n");
}
