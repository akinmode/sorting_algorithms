#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @array: input unordered array
 * @size: size of array
 * Return: prints ordered array
*/
void bubble_sort(int *array, size_t size) {

    int i, tmp = 0, maxpos = 0, posswap = 1;

    maxpos = size - 1;
	if (array == NULL || size < 2)
		return;

	for (i = 0; i < maxpos; i++)
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			posswap = 1;
			print_array(array, size);
		}

		if (posswap == 1 && i == maxpos - 1)
			i = -1, posswap = 0, --maxpos;
	}
}
