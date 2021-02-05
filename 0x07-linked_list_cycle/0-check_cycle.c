#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: head of the list
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list)
{
	listint_t *current1, *current2;

	if (list == NULL)
		return (0);
	
	current1 = list;
	current2 = list;

	while (current2->next != NULL && current2->next->next != NULL)
	{
		current1 = current1->next;
		current2 = current2->next->next;

		if (current1 == current2)
			return (1);
	}

	return (0);
}
