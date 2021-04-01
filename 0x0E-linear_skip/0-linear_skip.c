#include "search.h"

/**
 * linear_skip - Looks for some value in a sorted skip list of integers.
 * @list: list.
 * @value: value to look for.
 * Return: pointer to the node where value is located.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *aux;
	size_t index1, index2;

	while (list->next && list->n < value)
	{
		if (list->express)
		{
			aux = list;
			list = list->express;
			printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
			if (!list->express && value > list->n)
				aux = list;
		}
		else
			list = list->next;
	}
	index1 = aux->index, index2 = list->index;
	printf("Value found between indexes [%lu] and [%lu]\n", index1, index2);
	while (aux->next && aux->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", aux->index, aux->n);
		aux = aux->next;
		if (!aux->next)
			printf("Value checked at index [%lu] = [%d]\n", aux->index, aux->n);
	}
	if (aux->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n", aux->index, aux->n);
		return (aux);
	}
	return (NULL);
}
