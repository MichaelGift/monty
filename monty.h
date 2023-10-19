#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);

void add_top_two(stack_t **head, unsigned int counter);
void divide_top_two(stack_t **head, unsigned int counter);
int execute_opcode(char *content,
		stack_t **stack, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void modulo(stack_t **head, unsigned int counter);
void multiply_top_two(stack_t **head, unsigned int counter);
void do_nothing(stack_t **head, unsigned int counter);
void print_stack(stack_t **head, unsigned int counter);
void print_char(stack_t **head, unsigned int counter);
void print_int(stack_t **head, unsigned int counter);
void print_top(stack_t **head, unsigned int counter);
void print_str(stack_t **head, unsigned int counter);
void add_node(stack_t **head, unsigned int counter);
void print_q_top(stack_t **head, unsigned int counter);
void add_queue(stack_t **head, int n);
void rotate_stack_top(stack_t **head,  __attribute__((unused)) unsigned int counter);
void rotate_stack_bottom(stack_t **head, __attribute__((unused)) unsigned int counter);
void print_s_top(stack_t **head, unsigned int counter);
void substract(stack_t **head, unsigned int counter);
void swap_top_two(stack_t **head, unsigned int counter);
#endif
