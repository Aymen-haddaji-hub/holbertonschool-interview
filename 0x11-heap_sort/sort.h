#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void swap(int *i, int *j);
void sifdown(int *arr, size_t n, int i, size_t size);

#endif /* SORT_H */
