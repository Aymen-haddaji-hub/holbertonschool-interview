#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array
 * @array: Pointer to the first element of the array to search in
 * @size: Number of element in array
 * @value: The value to search for
 *
 * Return: Index where value is located, otherwise return NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t first = 0;
	size_t last = size - 1;
	size_t index;

	if (!array)
		return (-1);
	while (first <= last)
	{
		printf("Searching in array: ");
		print_array(array, first, last);
		printf("\n");

		index = (first + last) / 2;
		if (array[index] == value && array[index - 1] != value)
			return (index);
		else if (array[index] < value)
			first = index + 1;
		else
			last = index;
	}
	return (-1);
}

/**
 * print_array - Prints an array recursibely
 * @array: Pointer to the first element in the array
 * @first: Index of the printing first
 * @size: Size of the array
 */
void print_array(int array[], size_t first, size_t size)
{
	if (first > size)
		return;
	printf("%d", array[first]);
	if (first < size)
		printf(", ");
	print_array(array, first + 1, size);
}
