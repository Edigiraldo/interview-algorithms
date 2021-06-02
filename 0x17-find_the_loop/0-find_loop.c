#include "lists.h"

/**
 * loop_located - Function that checks if the loop was located.
 * @head: pointer to a node in the list.
 * @helper: pointer to a node in the list.
 *
 * Return: The pointer where the loop start.
 */
listint_t *loop_located(listint_t *head, listint_t *helper)
{
	while (head != helper)
	{
		head = head->next;
		helper = helper->next;
	}

	return (head);
}

/**
 * find_listint_loop - Function that finds the loop in a linked list.
 * @head: pointer to the head of the list.
 *
 * Return: The address of the node where the loop starts, otherwise NULL.
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *first, *second;

	if (!head)
		return (0);

	first = head->next;
	second = head->next->next;
	while (first && second && second->next)
	{
		first = first->next;
		second = second->next->next;
		if (first == second)
			return (loop_located(head, second));
	}

	return (0);
}
