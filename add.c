#include "monty.h"

/**
 * add_top_two - adds the top two elements of the stack.
 * @head: Pointer to stacks head.
 * @counter: line number
 * Return: no return
 */
void add_top_two(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int stack_len = 0, sum;

	current = *head;

	while (current)
	{
		current = current->next;
		stack_len++;
	}
	if (stack_len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	sum = current->n + current->next->n;
	current->next->n = sum;
	*head = current->next;
	free(current);
}

