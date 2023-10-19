#include "monty.h"
/**
 * print_stack - Prints the elements of the stack.
 * @head: Pointer to stack head
 * @counter: Unused line number
 * Return: no return
 */
void print_stack(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *head;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

