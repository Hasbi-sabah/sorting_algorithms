#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: array to be sorted
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, i, j, temp;
	int dummy = *array;

	if (size <= 1)
		return;
	while (gap < (int)size)
		gap = gap * 3 + 1;
	while (gap)
	{
		for (j = gap; j < (int)size; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i] > array[i + gap])
				{
					temp = array[i];
					array[i] = array[i + gap];
					array[i + gap] = temp;
				}
			}
		}
		gap = (gap - 1) / 3;
		if (dummy != *array)
			print_array(array, size);
	}
}
