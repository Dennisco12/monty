#include "monty.h"

/**
 * _mod - This function compuite the modulus of the top two elements
 * in the stack
 * @stack: A doubly linked list
 * @line_number: The line number of each command
 */

void _mod(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *temp, *temp2;
	int p, s;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can;t mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	p = temp->n;
	s = (temp->next)->n;

	temp2 = malloc(sizeof(stack_t1));
	if (!temp2)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp2->n = s % p;
	temp2->next = (temp->next)->next;
	temp2->prev = NULL;
	*stack = temp2;
	temp->next = NULL;
}

/**
 * _nop - This function does nothing at all
 * @stack: A doubly linked list
 * @line_number: The line number of each command
 */

void _nop(stack_t1 **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _mul - A function that computes the product of the first two elements
 * of the stack
 * @stack: A doubly linked list
 * @line_number: The line number of each command
 */

void _mul(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *temp, *temp2;
	int p, s;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can;t mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	p = temp->n;
	s = (temp->next)->n;

	temp2 = malloc(sizeof(stack_t1));
	if (!temp2)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp2->n = p * s;
	temp2->next = (temp->next)->next;
	temp2->prev = NULL;
	*stack = temp2;
	temp->next = NULL;
}

/**
 * _div - A function that divides the top two elements
 * of a stack
 * @stack: A doubly linked list
 * @line_number: The line number of each command
 */

void _div(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *temp, *temp2;
	int p, s;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	p = temp->n;
	s = (temp->next)->n;

	if (p == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp2 = malloc(sizeof(stack_t1));
	if (temp2 == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp2->n = s / p;
	temp2->next = (temp->next)->next;
	temp2->prev = NULL;
	*stack = temp2;
	temp->next = NULL;
}


/**
 * _sub - A function that subtacts the top two elements of the stack
 * @stack: A doubly linked list
 * @line_number: The line number of each command
 */

void _sub(stack_t1 **stack, unsigned int line_number)
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

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't subtract, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	p = temp->n;
	s = (temp->next)->n;

	temp2->n = p - s;
	temp2->next = (temp->next)->next;
	temp2->prev = NULL;
	*stack = temp2;
	temp->next = NULL;
}

