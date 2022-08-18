#include "monty.h"

/**
 * _pall - A function that prints all the elements of a stack
 * @stack: the doubly linked list
 * @line_number: The line number of each command
 */

void _pall(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *temp;
	(void)line_number;

	temp = malloc(sizeof(stack_t1));
	if (!temp)
	{
		fprintf(stderr, "malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (!temp)
	{
		fprintf(stderr, "Empty list\n");
		exit(EXIT_FAILURE);
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 * _swap - A function that swaps the first two elements of a stack
 * @stack: A doubly linked list
 * @line_number: The line number of each command
 */

void _swap(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *head;
	int temp;

	head = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (head->prev != NULL)
		head = head->prev;

	if (head->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap,stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = head->n;
	head->n = (head->next)->n;
	(head->next)->n = temp;
}

/**
 * _pint - A function that prints only the top element of a stack
 * @stack: A doubly linked list
 * @line_number: The line number of each command
 */

void _pint(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *temp;

	temp = *stack;
	if (!temp)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp->prev != NULL)
		temp = temp->prev;

	printf("%d\n", temp->n);
}


/**
 * _pop - A function that removes the top element of a stack
 * @stack: A doubly linked list
 * @line_number: The line number of each command
 */

void _pop(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *temp;
	stack_t1 *first;

	first = *stack;
	if (!first)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	temp = first->next;
	temp->prev = NULL;
	first->next = NULL;

	*stack = temp;
}


/**
 * _add - A function that adds the top two elements in a stack
 * @stack: The doubly linked list
 * @line_number: The line number of each command
 */

void _add(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *temp, *temp2;
	int p, s;

	temp = *stack;
	temp2 = malloc(sizeof(stack_t1));
	if (!temp2)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (!temp || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	p = temp->n;
	s = (temp->next)->n;

	temp2->n = p + s;
	temp2->next = (temp->next)->next;
	temp2->prev = NULL;
	*stack = temp2;
	temp->next = NULL;
}
