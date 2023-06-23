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
