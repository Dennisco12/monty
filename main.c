#include "monty.h"

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	char *buffer;
	stack_t1 *stack;
	unsigned int line_number;
	int i = 0;
	int *str;

	stack = NULL;
	buffer = read_file(argv[1]);
	tokenise(buffer, stack, line_number);

	freelist(stack);

	return (0);
}
