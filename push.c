#include "monty.h"

/**
 * _push - A function that adds an element at the top of a stack
 * @stack: The doubly linked list
 * @line_number: The line number of each command
 */

void _push(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *temp;
	stack_t1 *new;
	char *arg;

	temp = *stack;
	new = malloc(sizeof(stack_t1));

	arg = push_args[line_number - 1];
	if (atoi(arg) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(arg);
	new->prev = NULL;
	new->next = temp;
	if (temp != NULL)
		temp->prev = new;

	*stack = new;
}
