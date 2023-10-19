#include "monty.h"
/**
 * modulo - Computes the remainder of the division of the second
 * top element of the stack by the top element of the stack.
 * @head: Pointer to the stack's head
 * @counter: Line number
 * Return: No return value
 */
void modulo(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int stack_len = 0, result;

	current = *head;

	while (current)
	{
		current = current->next;
		stack_len++;
	}
	if (stack_len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result = current->next->n % current->n;
	current->next->n = result;
	*head = current->next;
	free(current);
}

