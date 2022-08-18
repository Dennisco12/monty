#include "monty.h"

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	char *buffer;
	stack_t1 *stack;
	unsigned int line_number;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stack = NULL;
	buffer = read_file(argv[1]);
	line_number = 0;
	tokenise(buffer, stack, line_number);

	freelist(stack);

	return (0);
}
