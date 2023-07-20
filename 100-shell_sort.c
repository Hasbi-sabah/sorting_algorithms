#include "sort.h"

/**
 * shell_sort - sort an array using shell sort algorithm
 * @array: array to be sorted
 * @size: size of the array
*/
void shell_sort(int *array, size_t size)
{
    size_t gap = 1, i, j; 
    int tmp;

    while (gap < size / 3)
    {
        gap = gap * 3 + 1;
    }

    for (;gap > 0; gap = (gap - 1) / 3)
    {
        for (i = gap; i < size; i++)
        {
            tmp = array[i];
            for (j = i; (j > gap - 1 && array[j - gap] >= tmp); j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = tmp;
        }
        print_array(array, size);
    }
}