#include "slide_line.h"

/**
 * push_int_left - moves all intger to the left.
 * @array: a pointer to an integer array
 * @size: number of items in the array
 */
void push_int_left(int *array, size_t size)
{
	size_t i, tmp;

	for (i = 1; i < size; i++)
	{
		if (array[i] != 0)
		{
			tmp = i;
			while (array[i - 1] == 0 && i > 0)
			{
				array[i - 1] = array[i];
				array[i] = 0;
				--i;
			}
			i = tmp;
		}
	}
}

/**
 * push_int_right - moves all ints to the right.
 * @array: a pointer to an integer array
 * @size: number of items in the array
 */
void push_int_right(int *array, size_t size)
{
	size_t i, tmp;

	for (i = size - 2; i + 1 > 0; i--)
	{
		if (array[i] != 0)
		{
			tmp = i;
			while (array[i + 1] == 0 && i < size - 1)
			{
				array[i + 1] = array[i];
				array[i] = 0;
				++i;
			}
			i = tmp;
		}
	}
}

/**
 * merge_left - merge identical ints in the left.
 * @array: a pointer to an integer array
 * @size: number of items in the array
 */
void merge_left(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] == array[i + 1])
		{
			array[i + 1] *= 2;
			array[i] = 0;
			++i;
		}
	}
}

/**
 * merge_right - merge identical ints in the right.
 * @array: a pointer to an integer array
 * @size: number of items in the array
 */
void merge_right(int *array, size_t size)
{
	size_t i;

	for (i = size - 1; i + 1 > 1; i--)
	{
		if (array[i] == array[i - 1])
		{
			array[i - 1] *= 2;
			array[i] = 0;
			--i;
		}
	}
}

/**
 * slide_line - slides and merges an array of integers.
 * @line: points to an array of integers containing size elements,
 * @size: number of elements in the array.
 * @direction: left or right macros.
 * Return: 1 on success, 0 on failure.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || size < 1)
		return (0);
	switch (direction)
	{
		case SLIDE_LEFT:
			push_int_left(line, size);
			merge_left(line, size);
			push_int_left(line, size);
			break;
		case SLIDE_RIGHT:
			push_int_right(line, size);
			merge_right(line, size);
			push_int_right(line, size);
	}
	return (1);
}
