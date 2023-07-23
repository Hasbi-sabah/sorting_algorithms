#include "sort.h"

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
	int pivot = array[high], temp;
	int i = low - 1;
	int j = high + 1;

	while (i < j)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	return (i);
}

/**
 * splitter - recusrsive function
 * @array: array to be sorted
 * @low: the low index
 * @high: the high index
 * @size: size of the array
 */
void splitter(int *array, int low, int high, size_t size)
{
	int p_idx;

	if (low < high)
	{
		p_idx = partitionner(array, low, high, size);
		splitter(array, low, p_idx - 1, size);
		splitter(array, p_idx, high, size);
	}
}
/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	splitter(array, 0, size - 1, size);
}
