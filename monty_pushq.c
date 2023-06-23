/**
 * is_valid_number - Check if a string is a valid number
 *
 * @str: String to check
 * Return: 1 if valid number, 0 otherwise
 */
int is_valid_number(char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-')
		i++;

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}

	return (1);
}

/**
 * create_stack_node - Create a new stack node with the given value
 *
 * @value: Value to assign to the new node
 * Return: Pointer to the newly created node, or NULL on failure
 */
stack_t *create_stack_node(int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
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

	if (tokens[1] == NULL || !is_valid_number(tokens[1]))
		return (f_errors(0, lineNumber));

	newNode = create_stack_node(atoi(tokens[1]));
	if (newNode == NULL)
		return (usage_error(0));

	if (!(*stack))
		*stack = newNode;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;

		newNode->prev = tmp;
		tmp->next = newNode;
	}

	return (EXIT_SUCCESS);
}
