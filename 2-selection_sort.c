#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int i, j = 0, smallest, s_index;

	while (j != (int)size - 1)
	{
		smallest = array[j];
		for (i = j; i < (int)size; i++)
		{
			if (smallest > array[i])
			{
				smallest = array[i];
				s_index = i;
			}
		}
		if (array[j] != array[s_index])
		{
			array[s_index] = array[j];
			array[j] = smallest;
			print_array(array, size);
		}
		j++;
	}
}
