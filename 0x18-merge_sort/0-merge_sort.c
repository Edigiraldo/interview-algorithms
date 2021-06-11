#include "sort.h"

/**
 * print - Function to print message.
 * @array: array of integers.
 * @right: right subarry.
 * @left: left subarry.
 * @lidx: index of the left subarray.
 * @ridx: index of the right subarray.
 * @size: size of array.
 * Return: Nothing(void).
 */
void print(int *array, int *right, int *left, int lidx, int ridx, size_t size)
{
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, lidx);
	printf("[right]: ");
	print_array(right, ridx);
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge - Helper function to merge two subarrays of integer.
 * @array: array of integers.
 * @right: right subarry.
 * @left: left subarry.
 * @size: size of array.
 * Return: Nothing(void).
 */
void merge(int *array, int *right, int *left, size_t size)
{
	int i = 0, j = 0, k = 0;
	int lidx, ridx;

	lidx = size / 2;
	ridx = size - lidx;

	while (i < lidx && j < ridx)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < lidx)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < ridx)
	{
		array[k] = right[j];
		j++;
		k++;
	}
	print(array, right, left, lidx, ridx, size);
}

/**
 * merge_sort - Function that sorts an array of integers in ascending order.
 * using the Merge Sort algorithm.
 * @array: array of integers to sort.
 * @size: size of array.
 * Return: Nothing(void).
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, idx;
	int right[300], left[300];

	mid = size / 2;

	if (size < 2 || array == NULL)
		return;

	for (idx = 0; idx < mid; idx++)
		left[idx] = array[idx];

	for (idx = mid;  idx < size; idx++)
		right[idx - mid] = array[idx];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, right, left, size);
}
