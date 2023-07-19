#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order with Bubble sort
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int i, j = 1, temp, sorted = 0;

	while (!sorted)
	{
		sorted = 1;
		for (i = 0; i < (int)size - j; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				sorted = 0;
				print_array(array, size);
			}
		}
		j++;
	}
}
