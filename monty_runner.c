#include "monty.h"

/**
 * monty_run - Runs a Monty bytecodes script.
 *
 * @file: File descriptor for an open Monty bytecodes script.
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on error.
 */
int monty_run(FILE *file)
{
	stack_t *stack = NULL;
	char *line = NULL, **tokens = NULL, delimiters[] = " \n\t\a\b";
	size_t line_length = 0, mode = 1;
	unsigned int line_number = 0, exit_status = EXIT_SUCCESS;

	while (getline(&line, &line_length, file) != -1)
	{
		line_number++;
		if (is_empty_line(line, delimiters))
			continue;
		tokens = tokenize_line(line, delimiters);
		if (tokens[0][0] == '#' || strcmp(tokens[0], "nop") == 0)
		{
			free(tokens);
			continue;
		}
		else if (strcmp(tokens[0], "stack") == 0)
			mode = 1;
		else if (strcmp(tokens[0], "queue") == 0)
			mode = 0;
		else if (strcmp(tokens[0], "push") == 0 && mode == 0)
			exit_status = monty_push_queue(&stack, tokens, line_number);
		else if (strcmp(tokens[0], "push") == 0 && mode == 1)
			exit_status = monty_push_stack(&stack, tokens, line_number);
		else
			exit_status = execute_instruction(tokens, &stack, line_number);
		free(tokens);
		if (exit_status == EXIT_FAILURE)
			break;
	}
	free_stack(&stack);
	free(line);
	return (exit_status);
}

/**
 * tokenize_line - Tokenizes a line into separate tokens.
 *
 * @line: The line to be tokenized.
 * @delimiters: The delimiter characters.
 * Return: An array of tokens.
 */
char **tokenize_line(char *line, char *delimiters)
{
	char *token = NULL, **tokens = NULL;
	size_t buffer_size = 0;
	int token_index = 0;

	if (line == NULL || !*line)
		return (NULL);

	buffer_size = strlen(line);
	if (buffer_size == 0)
		return (NULL);
	tokens = malloc(buffer_size * sizeof(char *));
	if (tokens == NULL)
	{
		free(line);
		free(tokens);
		exit(monty_usage_error(0));
	}
	token = strtok(line, delimiters);
	if (token == NULL)
	{
		free(tokens);
		free(line);
		return (NULL);
	}
	while (token != NULL)
	{
		tokens[token_index] = token;
		token_index++;
		token = strtok(NULL, delimiters);
	}
	tokens[token_index] = '\0';
	return (tokens);
}

/**
 * monty_empty_line - Checks if a line is empty or contains only delimiters.
 *
 * @line: The line to be checked.
 * @delimiters: The delimiter characters.
 * Return: 1 if the line is empty or contains only delimiters, 0 otherwise.
 */
int monty_empty_line(char *line, char *delimiters)
{
	int char_index, delimiter_index;

	for (char_index = 0; line[char_index]; char_index++)
	{
		for (delimiter_index = 0; delimiters[delimiter_index]; delimiter_index++)
		{
			if (line[char_index] == delimiters[delimiter_index])
				break;
		}
		if (delimiters[delimiter_index] == '\0')
			return (0);
	}

	return (1);
}
