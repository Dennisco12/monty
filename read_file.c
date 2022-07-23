#include "monty.h"

/**
 * read_file - A function that reads into a file
 * @filename: The name of the file to be read
 * Return: The content of the file in a buffer
 */
char *read_file(char *filename)
{
	int fd, bytes_read;
	char *buffer;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	buffer = malloc(sizeof(char *) * 1024);
	bytes_read = read(fd, buffer, 1024);
	if (bytes_read == 0)
	{
		dprintf(2, "%s file is empty\n", filename);
		exit(EXIT_FAILURE);
	}
	close(fd);
	return (buffer);
}

char *push_args[50];

/**
 * tokenise - A function that tokenise its arguments
 * into single commands and put these commands in an array
 * @buffer: The string to be tokenised
 * @stack: a doubly linked list
 * @line_number: The line number for each command
 */

void tokenise(char *buffer, stack_t1 *stack, unsigned int line_number)
{
	char *token_line;
	char *token_str;
	char *line_arr[50];
	char *str_arr[50];
	int j = 0, n = 0;
	char *second;
	char *k = "-1";

	line_number = 1;
	token_line = strtok(buffer, "\n");
	line_arr[j] = token_line;
	j++;
	while (token_line != NULL)
	{
		token_line = strtok(NULL, "\n");
		line_arr[j] = token_line;
		j++;
	}
	j = 0;
	while (line_arr[j])
	{
		if (line_arr[j] == NULL)
		{
			dprintf(2, "L%d: line empty\n", j + 1);
			break;
		}
		str_arr[j] = strtok(line_arr[j], " ");
		if (strcmp("push", str_arr[j]) == 0)
		{
			second = strtok(NULL, " ");
			if (second == NULL || int_check(second) == 0)
				push_args[j] = k;
			else
				push_args[j] = second;
		}
		else
			push_args[j] = k;
		j++;
	}
	get_op(str_arr, stack);
}

/**
 * get_op - A function that takes string and fetches its corresponding
 * function
 * @str: The string input
 * @stack: A doubly linked list
 */
void get_op(char **str, stack_t1 *stack)
{
	int i = 0;
	int j = 0, k = 0;
	void (*oper)(stack_t1 **, unsigned int);
	instruction_t function[] = {
		{"push", _push},
		{"pall", _pall},
		{"swap", _swap},
		{"pint", _pint},
		{"pop", _pop},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"nop", _nop},
		{NULL, NULL},
	};

	if (str == NULL)
	{
		dprintf(2, "no instruction found\n");
		exit(EXIT_FAILURE);
	}
	while (str[j])
	{
		i = 0;
		while (function[i].opcode)
		{
			if (strcmp(str[j], function[i].opcode) == 0)
			{
				oper = function[i].f;
				break;
			}
			i++;
		}
		oper(&stack, j + 1);
		j++;
	}
	freelist(stack);
}