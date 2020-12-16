#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a node in a linked list.
 *
 * @head: double pointer to head of linked list.
 * @number: number to be stored in the new node.
 *
 * Return: pointer to new node or null if it fails.
 */

listint_t *insert_node(listint_t **head, int number)
{

	listint_t *new = NULL;
	listint_t *prev = NULL;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	prev = *head;
	while (prev->next != NULL && (prev->next)->n < number)
		prev = prev->next;

	new->next = prev->next;
	prev->next = new;

	return (new);
}
