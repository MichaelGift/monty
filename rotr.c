#include "monty.h"
/**
 *rotate_stack_bottom- this rotates the stack to the bottom
 *@head: is the stack head
 *@counter: line_number
 *Return: no return
 */
void rotate_stack_bottom(stack_t **head,
		__attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
