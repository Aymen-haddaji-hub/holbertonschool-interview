
#include "sort.h"
/**
 * swap - swap elements in a give array.
 * @array: array to print
 * @i: value to swap
 * @j: value to swap
 * @size: n elements inside array.
 */
void swap(int *i, int *j, int *array, size_t size)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
	print_array(array, size);
}
/**
 * heapify - heapify function
 * @array: array of numbers
 * @h: h
 * @b: b
 * @size: size of array
 * Return: void
 */
void heapify(int *array, int h, int b, size_t size)
{
	int biggest = b;
	int left = 2 * b + 1;
	int right = 2 * b + 2;

	if (left < h && array[left] > array[biggest])
		biggest = left;

	if (right < h && array[right] > array[biggest])
		biggest = right;

	if (biggest != b)
	{
		swap(&array[b], &array[biggest], array, size);
		heapify(array, h, biggest, size);
	}
}
/**
 * heap_sort - sort an array of integers in
 * ascending order using the Heap sort algorithm.
 * @array: array
 * @size: size of array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL)
		return;

	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i], array, size);
		heapify(array, i, 0, size);
	}
}
