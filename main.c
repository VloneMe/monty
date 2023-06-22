#include "monty.h"

/**
 * main - The entry point for the Monty  program.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: Exit status of the program.
 */
int main(int argc, char **argv)
{
	FILE *file = NULL;
	int exit_status = EXIT_SUCCESS;

	if (argc != 2)
		return (monty_usage_error(1));

	file = fopen(argv[1], "r");
	if (file == NULL)
		return (monty_open_error(argv[1]));

	exit_status = monty_run(file);

	fclose(file);
	return (exit_status);
}
