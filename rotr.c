#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom
 * @head: Pointer to the stack head
 * @count: Line number of the instruction
 *
 * Description: The last element of the stack becomes
 * the top element of the stack
 * Return: No return value
 */
void rotr(stack_t **head, __attribute__((unused)) unsigned int count)
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
