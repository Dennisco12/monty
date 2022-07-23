#include "monty.h"

/**
 * int_check - A function that checks if the input is a number
 * @str: The input
 * Return: 1 if inout is integer, and 0 if otherwise
 */
int int_check(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
