#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, j, max, c_size, counter;
	int *c_array;

	if (size <= 1)
		return;
	for (i = 0, max = array[0]; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	c_size = max + 1;
	c_array = malloc(sizeof(int) * (c_size));
	for (i = 0, counter = 0; c_array && i < c_size; i++)
	{
		for (j = 0; j < (int)size; j++)
		{
			if (array[j] == i)
				counter++;
		}
		c_array[i] = counter;
	}
	print_array(c_array, c_size);
	for (i = 1, j = 0; i < c_size; i++)
	{
		if (c_array[i] > c_array[i - 1])
		{
			array[j] = i;
			j++;
		}
	}
	free(c_array);
}
