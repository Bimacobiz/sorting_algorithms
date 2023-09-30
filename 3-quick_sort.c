#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_integers - swaps two integers in a given array
 * @m: pointer to the first integer that should be swapped
 * @n: pointer to the second integer to be swapped
 */
void swap_integers(int *m, int *n)
{
	int tmp;

	tmp = *m;
	*m = *n;
	*n = tmp;
}

/**
 * lomuto_partition - uses the Lomuto partition scheme to
 * order a subset of integers
 * @array: the array of integers that should be sorted
 * @size: the size of the array that should be ordered
 * @low: the starting index of the subset that should be ordered
 * @high: the ending index of the subset that should be ordered
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pivot;
	int i;

	pivot = array + high;
	for (i = low; i < high; i++)
	{
		if (array[i] < *pivot)
		{
			if (i != low)
			{
				swap_integers(array + i, array + low);
				print_array(array, size);
			}
			low++;
		}
	}

	if (array[low] > *pivot)
	{
		swap_integers(array + low, pivot);
		print_array(array, size);
	}

	return (low);
}

/**
 * lomuto_sort - uses the Lomuto partition scheme to
 * order a subset of integers
 * @array: the array of integers that should be sorted
 * @size: the size of the array that should be ordered
 * @low: the starting index of the subset that should be ordered
 * @high: the ending index of the subset that should be ordered
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	int part;

	if (high - low > 0)
	{
		part = lomuto_partition(array, size, low, high);
		lomuto_sort(array, size, low, part - 1);
		lomuto_sort(array, size, part + 1, high);
	}
}

/**
 * quick_sort - uses the quick sort algorithm to sort integers
 * @array: the array of integers that should be sorted
 * @size: the size of the array that should be ordered
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
