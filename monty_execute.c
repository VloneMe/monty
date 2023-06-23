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
