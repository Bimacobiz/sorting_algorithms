#include "sort.h"

void swap_integers(int *m, int *n);
int lomuto_partition(int *array, size_t size, int sideA, int sideB);
void lomuto_sort(int *array, size_t size, int sideA, int sideB);
void quick_sort(int *array, size_t size);
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
 * lomuto_partition - uses the lomuto partition scheme to
 * order a subset of integers
 * @array: the array of intergers that should be sorted
 * @size: the size of the arry that should be ordered
 * @sideA: the starting index of the subset that should be
 * ordered
 * @sideB: the ending index of the the subset that should
 * be ordered
 */
int lomuto_partition(int *array, size_t size, int sideA, int sideB)
{
	int *pivot, low, high;

	pivot = array + sideB;
	for (low = high = sideA; low < sideB; low++)
	{
		if (array[low] < *pivot)
		{
			if (low < high)
			{
				swap_integers(array + low, array + high);
				print_array(array, size);
			}
			high++;
		}
	}

	if (array[high] > *pivot)
	{
		swap_integers(array + high, pivot);
		print_array(array, size);
	}

	return (high);
}

/**
 * lomuto_sort - uses the lomuto partition scheme to
 * order a subset of integers
 * @array: the array of intergers that should be sorted
 * @size: the size of the arry that should be ordered
 * @sideA: the starting index of the subset that should be
 * ordered
 * @sideB: the ending index of the the subset that should
 * be ordered
 */
void lomuto_sort(int *array, size_t size, int sideA, int sideB)
{
	int part;

	if (sideB - sideA > 0)
	{
		part = lomuto_partition(array, size, sideA, sideB);
		lomuto_sort(array, size, sideA, part - 1);
		lomuto_sort(array, size, part + 1, sideB);
	}
}

/**
 * quick_sort - uses the quick sort algorithm to sort integers
 * @array: the array of intergers that should be sorted
 * @size: the size of the arry that should be ordered
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
