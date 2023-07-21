#include "sort.h"

/**
 * selection_sort - sort an array using selection sort
 * @array: the array to be sorted
 * @size: the size of the array
*/

void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, index = 0;

	for (i = 0; i < size - 1; i++)
	{
		index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[index])
				index = j;
		}
		if (index != i)
		{
			tmp = array[i];
			array[i] = array[index];
			array[index] = tmp;
			print_array(array, size);
		}
	}
}
