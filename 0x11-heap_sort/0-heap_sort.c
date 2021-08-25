#include "sort.h"

/**
 * siftdown - Implementation siftdown algo.
 * @arr: ponter to a given array.
 * @n: element of an array.
 * @i: index.
 * @size: unedited size of original array.
 */
void siftdown(int *arr, size_t n, int i, size_t size)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < (int) n && arr[l] > arr[largest])
		largest = l;

	if (r < (int) n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		print_array(arr, size);
		siftdown(arr, n, largest, size);
	}
}

/**
 * swap - Swap tow elements of a given array.
 * @i: source.
 * @j: destination.
 */
void swap(int *i, int *j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * heap_sort - Sorts an array of integers in ascending
 * order using the Heap sort algorithm
 * @array: An pointer to an array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (size == 0 || size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		siftdown(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		siftdown(array, i, 0, size);
	}
}
