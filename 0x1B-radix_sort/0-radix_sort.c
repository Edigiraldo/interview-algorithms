#include "sort.h"

/**
 * Max - A utility function to get maximum value in an array.
 * @arr: array.
 * @n: len of array.
 * Return: maximum value.
 */
int Max(int arr[], unsigned int n)
{
	int mx = arr[0];
	unsigned int i;

	for (i = 1; i < n; i++)
	{
		if (arr[i] > mx)
			mx = arr[i];
	}
	return (mx);
}

/**
 * sortingcount - A function to do counting sort.
 * @array: array to sort.
 * @exp: exponent.
 * @output: array to allocate info.
 * @size: size of the array.
 * Return: void.
 */
void sortingcount(int *array, int size, int exp, int *output)
{
	int i;
	int count[10] = {0};

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
}
/**
 * radix_sort - radix sort
 * @array: array to sort
 * @size: size to array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max = 0;
	int exp, *output = '\0';

	if (array == NULL || size < 2)
		return;
	max = Max(array, size);
	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		sortingcount(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
