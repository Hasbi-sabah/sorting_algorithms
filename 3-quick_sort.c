#include "sort.h"

/**
 * quick_sort - sort an array using the quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
*/
void quick_sort(int *array, size_t size)
{
    recursion(array, 0, (int)size - 1, size);
}

/**
 * recursion - sort the array using recursion
 * @array: the array to be sorted
 * @low: the lowest index
 * @hight: the highest index
*/
void recursion(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int index = split(array, low, high, size);
/*         int index = partition(array, low, high, size); */
        recursion(array, low, index - 1, size);
        recursion(array, index + 1, high, size);
    }
}
/**
 * swap - swap the value inside x with value inside y
 * @x: the value to be swapped
 * @y: the other value to be swapped
*/
void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

/**
 * split - split the array into 2 partitions
 * @array: the array to be splitted
 * @low: the low index
 * @hight: high index
 * Return: the index of the pivot
*/
int split(int *array, int low, int high, size_t size)
{
    int index = array[high], i = low - 1, j;

    for (j = low; j < high; j++)
    {
        if (array[j] < index && array[++i] != array[j])
        {
            swap(&array[i], &array[j]);
            print_array(array, size);
        }
    }
    if (array[++i] != array[high])
    {
        swap(&array[i], &array[high]);
        print_array(array, size);
    }
    return i;
}
/* int partition(int *arr, int low, int high, size_t size)
{
    int pivot = arr[high];
    int tmp, j, i = low - 1;

    for (j = low; j < high; j++)
    {
        if (arr[j] < pivot &&  arr[j] != arr[++i])
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            print_array(arr, size);
        }
    }
    if (arr[high] != arr[++i])
    {
        tmp = arr[i];
        arr[i] = arr[high];
        arr[high] = tmp;
        print_array(arr, size);
    }
    return (i);
} */