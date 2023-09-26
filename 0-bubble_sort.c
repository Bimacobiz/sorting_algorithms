#include "sort.h"
bool isSorted(int *array, size_t size);
void bubble_sort(int *array, size_t size);
/**
 * isSorted - Check if an array is sorted in ascending order.
 * @array: Pointer to the array to be checked.
 * @size: Number of elements in the array.
 *
 * Return: True if the array is sorted, false otherwise.
 */
bool isSorted(int *array, size_t size)
{
	size_t p;

	if (size <= 1)
	{
		return (true);
	}

	for (p = 0; p < size - 1; p++)
	{
		if (array[p] > array[p + 1])
		{
			return (false);
		}
	}

	return (true);
}

/**
 *bubble_sort - uses the bubble sort algorithm to sort
 *an array of integers in ascending order.
 *@array: a pointer to the location of the arrays to be
 *sorted
 *@size: the number of elements to sort
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	bool swapped;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = true;
			}
		}

		print_array(array, size);

		if (!swapped)
			break;
	}
}
