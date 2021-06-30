#include "list.h"


/**
 * add_node_end - adds a new node at the end
 * of a circular double linked list.
 *
 * @list: pointer to head of circular linked list.
 * @str: string to be stored in the new node.
 *
 * Return: the address of the new element, or NULL if it failed.
 */

List *add_node_end(List **list, char *str)
{
	List *new = NULL; 
	List *last = NULL;

	if (list == NULL || str == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	if (*list == NULL)
	{
		new->next = new->prev = new;
		*list = new;
		return (new);
	}

	last = (*list)->prev;

	last->next = new;
	new->next = *list;
	new->prev = last;

	(*list)->prev = new;

	return (new);
}

/**
 * add_node_begin - adds a new node at the beginning
 * of a circular double linked list.
 *
 * @list: pointer to head of circular linked list.
 * @str: string to be stored in the new node.
 *.
 * Return: the address of the new element, or NULL if it failed.
 */

List *add_node_begin(List **list, char *str)
{
	List *new = NULL;
	List *last = NULL;

	if (list == NULL || str == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	if (*list == NULL)
	{
		new->next = new->prev = new;
		*list = new;
		return (new);
	}

	last = (*list)->prev;

	new->next = (*list);
	new->prev = last;
	(*list)->prev = last->next = new;
	*list = new;

	return (new);
}
