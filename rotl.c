#include "monty.h"

/**
 * rotl - Rotates the stack to the top
 * @stack: Pointer to the stack head
 * @count: Line number of the instruction
 *
 * Description: The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
 * Return: No return value
 */
#include "monty.h"

/**
 * rotl - Rotates the stack to the top
 * @stack: Pointer to the stack head
 * @count: Line number of the instruction
 *
 * Description: The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
 * Return: No return value
 */
void rotl(stack_t **head,  __attribute__((unused)) unsigned int count)
{
	stack_t *temp = *head, *new;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	new = (*head)->next;
	new->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = new;
}
