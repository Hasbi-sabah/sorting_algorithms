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
	int *pivot = array + high;
	int i = low - 1;
    	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < *pivot);
		do {
			j--;
		} while (array[j] > *pivot);
		if (i >= j)
			return (j);
		swapper(array + i, array + j);
		print_array(array, size);
	}
}
/**
 * sorter - recusrsive function
 * @array: array to be sorted
 * @low: the low index
 * @high: the high index
 */
void splitter(int *array, int low, int high, int size)
{
	int p_idx;

	if (low >= high)
		return;
	p_idx = partitionner(array, low, high, size);
	splitter(array, low, p_idx - 1, size);
	splitter(array, p_idx + 1, high, size);

}
void quick_sort_hoare(int *array, size_t size)
{
	if (size <= 1)
		return;
	splitter(array, 0, size - 1, size);
}
