#include "sort.h"
/**
 * mover - moves the contents of the array into left and right subarrays
 * @array: source array
 * @left: left subarray
 * @right: right subarray
 * @l_size: size of the left subarray
 * @r_size: size of the right subarray
 * @low: lower index of array
 * @middle: index of the middle of the array
 */
void mover(int *array, int *left, int *right, int l_size, int r_size,
		int low, int middle)
{
	int i;

	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < l_size; i++)
	{
		left[i] = array[low + i];
		printf("%d", left[i]);
		if (i < l_size - 1)
			printf(", ");
		else
			printf("\n");
	}
	printf("[right]: ");
	for (i = 0; i < r_size; i++)
	{
		right[i] = array[middle + 1 + i];
		printf("%d", right[i]);
		if (i < r_size - 1)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 * merger - sorts and merges the left and right subarrays
 * @array: the array to be sorted
 * @low: lowest index of array
 * @middle: index of the middle of the array
 * @high: highest index of array
 */
void merger(int *array, int low, int middle, int high)
{
	int i, j, k;
	int *left, *right, *subarr;
	int l_size = middle - low + 1;
	int r_size = high - middle;

	subarr = malloc(sizeof(int) * (high - low + 1));
	left = subarr;
	right = subarr + (middle - low + 1);
	mover(array, left, right, l_size, r_size, low, middle);
	for (i = 0, j = 0, k = low; i < l_size && j < r_size; k++)
	{
		if (left[i] <= right[j])
			array[k] = left[i], i++;
		else
			array[k] = right[j], j++;
	}


	while (i < l_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}
	while (j < r_size)
	{
		array[k] = right[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	for (i = low; i < k; i++)
	{
		printf("%d", array[i]);
		if (i < k - 1)
			printf(", ");
		else
			printf("\n");
	}
	free(subarr);
}

/**
 * splitter - splits the array recusively
 * @array: array to be split
 * @low: lower boundary
 * @high: higher boundary
 */
void splitter(int *array, int low, int high)
{
	int middle;

	if (low >= high)
		return;
	middle = low + (high - low) / 2;
	if (middle - low >= high - middle)
		middle--;
	splitter(array, low, middle);
	splitter(array, middle + 1, high);
	merger(array, low, middle, high);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (size <= 1)
		return;
	splitter(array, 0, size - 1);
}
