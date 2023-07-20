#include "sort.h"

/**
 * swapper - swaps 2 pointers
 * @x: pointer 1
 * @y: pointer 2
 */
void swapper(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partitionner - partitions the array using lomutos method
 * @array: array to be sorted
 * @low: the low index
 * @high: the high index
 * @size: size of the array
 * Return: index of pivot
 */
int partitionner(int *array, int low, int high, size_t size)
{
	int *pivot = &array[high];
	int i = low, j;

	(void) size;
	for (j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			swapper(&array[i], &array[j]);
			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}
	swapper(&array[i], pivot);
	if (array[i] != *pivot)
		print_array(array, size);
	return (i);
}
/**
 * sorter - recusrsive function
 * @array: array to be sorted
 * @low: the low index
 * @high: the high index
 * @size: size of the array
 */
void sorter(int *array, int low, int high, size_t size)
{
	int p_idx;

	if (low < high)
	{
		p_idx = partitionner(array, low, high, size);
		sorter(array, low, p_idx - 1, size);
		sorter(array, p_idx + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	sorter(array, 0, size - 1, size);
}
