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
	size_t s;
	size_t z;
	size_t k;
	int temp;
    	bool swapped;

	if (size == 0) 
	{
        printf("The array is empty.\n");
        return;
	}
	if (isSorted(array, size))
	{
		printf("Array Already Sorted.\n");
		return;
	}
	for (s = 0; s < size - 1; s++)
	{
        swapped = false;

        for (z = 0; z < size - s - 1; z++)
        {
            if (array[z] > array[z + 1])
            {
                temp = array[z];
                array[z] = array[z + 1];
                array[z + 1] = temp;
                swapped = true;
		
                printf("%lu-%lu: ", (unsigned long)z, (unsigned long)(z + 1));
		for (k = 0; k < size; k++)
                {
                    printf("%d ", array[k]);
                }
                printf("\n");
            }
        }

        if (!swapped)
        {
            break;
        }
    }

    printf("Array sorted successfully.\n");
}
