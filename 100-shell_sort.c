#include "sort.h"

/**
 * swap - Function that swaps two values
 * @a: Fisrt value
 * @b: Second value
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

/**
 * shell_sort - sort an array using shell sort
 * @array: array to be sorted
 * @size: size of the array
*/
void shell_sort(int *array, size_t size)
{
	int gap = 1, i, j;

	if (size == 1 || array == NULL)
		return;

	while (gap < (int) size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (j = gap; j < (int) size; j++)

			for (i = j - gap; i >= 0; i = i - gap)
			{
				if (array[i + gap] > array[i])
					break;
				swap(&array[i + gap], &array[i]);
			}

		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}

