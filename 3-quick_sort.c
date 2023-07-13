#include "sort.h"
#include <stddef.h>

/**
 * swap - Function that swaps two values
 *
 * @a: Fisrt value
 * @b: Second value
 * Return: 0
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

/**
 * partition - partion the array in to two sub array
 * @left: lower index
 * @right: higher index
 * @size: size of the array
 * Return: index at which the array is partitioned
*/
int _partition(int *array, int left, int right)
{
    int i, pivot = array[right], tmp_pivot_index;

    tmp_pivot_index = left - 1;
    for (i = left; i <= right - 1; i++)
    {
        if (array[i] <= pivot)
        {
            ++tmp_pivot_index;
            swap(&array[tmp_pivot_index], &array[i]);
        }
    }
    ++tmp_pivot_index;
    swap(&array[tmp_pivot_index], &array[right]);
    return (tmp_pivot_index);
}

/**
 * _quick_sort - sort array in quick sort algorithm
 * @array: the array to be sorted
 * @lower: lower index of sub array
 * @higher: higher index subarray
*/
void _quick_sort(int *array, int lower, int higher, size_t size)
{
    int part;

    if (lower >= higher || lower < 0)
        return;

    part = _partition(array, lower, higher);
    _quick_sort(array, lower, part - 1, size);
    _quick_sort(array, part + 1, higher, size);
    print_array(array, size);
}

/**
 * quick_sort - sort array in quick sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
    if (array == NULL)
        return;

    _quick_sort(array, 0, size - 1, size);
}
