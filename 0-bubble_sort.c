#include "sort.h"
/**
  * bubble_sort - sort the array in bubble sort algorith
  * @array: The array to be sorted
  * @size: size of the array
  */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	for (i = size; i > 1; i--)
	{
		for (j = 0; j < i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
