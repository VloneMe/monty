#include "monty.h"

/**
 * monty_usage_error - Prints a usage error message.
 *
 * @error_flag: Type of error: 0 for malloc failure, 1 for usage.
 * Return: EXIT_FAILURE.
 */
int monty_usage_error(int error_flag)
{
	char *error_messages[2] = {
		"Error: malloc failed",
		"USAGE: monty file"
	};

	fprintf(stderr, "%s\n", error_messages[error_flag]);
	return (EXIT_FAILURE);
}

/**
 * monty_open_error - Prints a file open error message.
 *
 * @filename: Name of the file failed to open.
 * Return: EXIT_FAILURE.
 */
int monty_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * monty_f_errors - Prints error messages related to stack operations.
 *
 * @error_flag: Index indicating the type of error.
 * @line_number: Line number in the file where the error occurred.
 * Return: EXIT_FAILURE.
 */
int monty_f_errors(int error_flag, unsigned int line_number)
{
	char *error_messages[] = {
		"usage: push integer",
		"can't pint, stack empty",
		"can't pop an empty stack",
		"can't swap, stack too short",
		"can't add, stack too short",
		"can't sub, stack too short",
		"can't div, stack too short",
		"division by zero",
		"can't mul, stack too short",
		"can't mod, stack too short",
		"can't pchar, value out of range",
		"can't pchar, stack empty"
	};

	fprintf(stderr, "L%d: %s\n", line_number, error_messages[error_flag]);
	return (EXIT_FAILURE);
}
