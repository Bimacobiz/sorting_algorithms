#include "sort.h"

void swap_integers(int *m, int *n);
void selection_sort(int *array, size_t size);
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
 * selection_sort - uses the selection sort algorithm to sort an array
 * of integers
 * @array: pointer to the integers to sort
 * @size: represents the number of items in the array
 */
void selection_sort(int *array, size_t size)
{
	int *current_min; /* Renamed from 'min' */
	size_t a, b; /* Renamed from 'i' and 'j' */

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		current_min = array + a; /* Renamed from 'min' */
		for (b = a + 1; b < size; b++)
			current_min = (array[b] < *current_min) ? (array + b) : current_min;

		if ((array + a) != current_min)
		{
			swap_integers(array + a, current_min); /* Renamed from 'min' */
			print_array(array, size);
		}
	}
}
