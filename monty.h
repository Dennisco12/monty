#ifndef MONTY_H
#define MONTY_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s1
{
        int n;
        struct stack_s1 *prev;
        struct stack_s1 *next;
} stack_t1;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t1 **stack, unsigned int line_number);
} instruction_t;

extern char *push_args[50];

char *read_file(char *filename);
void tokenise(char *str, stack_t1 *stack, unsigned int line_number);
void get_op(char **str, stack_t1 *stack);
int push_func(char *token_line);
int int_check(char *str);
void freelist(stack_t1 *stack);

	/*stack functions*/
void _push(stack_t1 **stack, unsigned int line_number);
void _pall(stack_t1 **stack, unsigned int line_number);
void _pop(stack_t1 **stack, unsigned int line_number);
void _pint(stack_t1 **stack, unsigned int line_number);
void _swap(stack_t1 **stack, unsigned int line_number);
void _add(stack_t1 **stack, unsigned int line_number);
void _sub(stack_t1 **stack, unsigned int line_number);
void _div(stack_t1 **stack, unsigned int line_number);
void _mul(stack_t1 **stack, unsigned int line_number);
void _mod(stack_t1 **stack, unsigned int line_number);
void _nop(stack_t1 **stack, unsigned int line_number);

#endif
