#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>
#include <stdio.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 0

int slide_line(int *line, size_t size, int direction);
/* left diection func */
void push_int_left(int *array, size_t size);
void merge_left(int *array, size_t size);
/* right direction func */
void push_int_right(int *array, size_t size);
void merge_right(int *array, size_t size);

#endif
