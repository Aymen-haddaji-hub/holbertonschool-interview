#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 1, 2, 5, 5, 6, 6, 7, 8, 9, 10
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 8, advanced_binary(array, size, 8));
    printf("size is : %ld\n", size);
    printf("size of array[0] is : %d\n", array[0]);
    printf("Found %d at index: %d\n\n", 5, advanced_binary(array, size, 5));
    printf("Found %d at index: %d\n\n", 999, advanced_binary(array, size, 999));
    printf("Found %d at index: %d\n", 10, advanced_binary(array, size, 10));

    return (EXIT_SUCCESS);
}
