#include "monty.h"

/**
 * monty_execute - Check for a command "opcode"
 *
 * @tokens: Tokens containing the opcode to execute
 * @stack: Doubly linked list representation of a stack
 * @lineNumber: Line number where the opcode was found
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure
 */
int monty_execute(char **tokens, stack_t **stack, unsigned int lineNumber)
{
	unsigned int i = 0;

	instruction_t opcodes[] = {
		{"pall", monty_print_all},
		{"pint", monty_print_top},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"sub", monty_sub},
		{"mul", monty_mul},
		{"div", monty_div},
		{"mod", monty_mod},
		{"pchar", monty_print_char},
		{"pstr", monty_print_string},
		{"rotl", monty_rotate_left},
		{"rotr", monty_rotate_right},
		{"null", NULL}
	};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, tokens[0]) == 0)
		{
			opcodes[i].f(stack, lineNumber);
			return (EXIT_SUCCESS);
		}
	}

	free_stack(stack);
	fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, tokens[0]);
	return (EXIT_FAILURE);
}

/**
 * monty_push - Push an element to the stack
 *
 * @stack: Pointer to the stack
 * @tokens: Tokens containing the command and argument
 * @lineNumber: Line number
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure
 */
int monty_push(stack_t **stack, char **tokens, unsigned int lineNumber)
{
	stack_t *newNode;
	int i = 0;

	if (tokens[1] == NULL)
		return (f_errors(0, lineNumber));

	while (tokens[1][i])
	{
		if (tokens[1][i] == '-' && i == 0)
		{
			i++;
			continue;
		}

		if (tokens[1][i] < '0' || tokens[1][i] > '9')
		{
			free_stack(stack);
			return (f_errors(0, lineNumber));
		}

		i++;
	}

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		return (usage_error(0));

	newNode->n = atoi(tokens[1]);

	if ((*stack) != NULL)
		(*stack)->prev = newNode;

	newNode->next = *stack;
	newNode->prev = NULL;
	*stack = newNode;

	return (EXIT_SUCCESS);
}

/**
 * monty_pushq - Push an element to the queue
 *
 * @stack: Pointer to the stack
 * @tokens: Tokens containing the command and argument
 * @lineNumber: Line number
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure
 */
int monty_pushq(stack_t **stack, char **tokens, unsigned int lineNumber)
{
	stack_t *newNode, *tmp = NULL;
	int i = 0;

	if (tokens[1] == NULL)
		return (f_errors(0, lineNumber));

	while (tokens[1][i])
	{
		if (tokens[1][i] == '-' && i == 0)
		{
			i++;
			continue;
		}

		if (tokens[1][i] < '0' || tokens[1][i] > '9')
		{
			free_stack(stack);
			return (f_errors(0, lineNumber));
		}

		i++;
	}

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		return (usage_error(0));

	newNode->n = atoi(tokens[1]);

	if (!stack || !(*stack))
	{
		(*stack) = newNode;
		return (EXIT_SUCCESS);
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;

		newNode->prev = tmp;
		tmp->next = newNode;
		return (EXIT_SUCCESS);
	}

	return (EXIT_FAILURE);
}

/**
 * monty_print_all - Print the values of the stack
 *
 * @stack: Pointer to the stack
 * @lineNumber: Line number
 * Return: Nothing
 */
void monty_print_all(stack_t **stack, unsigned int lineNumber)
{
	stack_t *tmp = *stack;
	(void)lineNumber;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
