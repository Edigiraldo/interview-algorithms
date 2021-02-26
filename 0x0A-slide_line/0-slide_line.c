#include "slide_line.h"

/**
 * slide_line - function that slides and merges
 * an array of integers
 * @n:
 * @line: points to an array of integers.
 * @size: number of elements in line.
 * @direction: direction in which the elements
 * must be slided & merged.
 * Return: 1 in success, and 0 in failure.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (size <= 0 || ((direction != SLIDE_LEFT) && (direction != SLIDE_RIGHT)))
		return (0);
	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else if (direction == SLIDE_RIGHT)
		slide_right(line, size);
	else
		return (0);
	return (1);
}

/**
 * slide_left - function that slides and merges
 * an array of integers to the left
 * @line: points to an array of integers.
 * @size: number of elements in line.
 * Return: 1 in success, and 0 in failure.
 */
void slide_left(int *line, size_t size)
{
	size_t i, k, p, q = 0;
	int aux[32];

	for (k = 0; k < size; k++)
		aux[k] = 0;
	for (p = 0; p < size; p++)
	{
		if (line[p] != 0)
			aux[q++] = line[p];
	}
	for (i = 0; i < size; i++)
	{
		if (aux[i] == aux[i + 1])
		{
			aux[i] += aux[i + 1];
			aux[i + 1] = 0;
		}
	}
	q = 0;
	for (k = 0; k < size; k++)
		line[k] = 0;
	for (p = 0; p < size; p++)
	{
		if (aux[p] != 0)
		{
			line[q++] = aux[p];
		}
	}
}

/**
 * slide_right - function that slides and merges
 * an array of integers to the right
 * @line: points to an array of integers.
 * @size: number of elements in line.
 * Return: 1 in success, and 0 in failure.
 */
void slide_right(int *line, size_t size)
{
	size_t q = 0, j;
	int aux[32], p, i, k;

	for (j = 0; j < size; j++)
		aux[j] = 0;
	q = size - 1;
	for (p = size - 1; p >= 0; p--)
	{
		if (line[p] != 0)
			aux[q--] = line[p];
	}
	for (i = size - 1; i >= 0; i--)
	{
		if (aux[i] == aux[i - 1])
		{
			aux[i] += aux[i - 1];
			aux[i - 1] = 0;
		}
	}
	for (k = size - 1; k >= 0; k--)
		line[k] = 0;
	q = size - 1;
	for (p = size - 1; p >= 0; p--)
	{
		if (aux[p] != 0)
			line[q--] = aux[p];
	}
}
