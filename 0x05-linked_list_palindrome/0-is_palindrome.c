#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * rec_pal - checks if a singly linked list is a palindrome.
 *
 * @left: left side
 * @right: right side
 * Return: 0 if it is not a palindrome 1 if it is a palindrome.
 */

int rec_pal(listint_t **left, listint_t *right)
{
	int data;

	if (right == NULL)
		return (1);

	data = rec_pal(left, right->next) && ((*left)->n == right->n);

	*left = (*left)->next;

	return (data);
}
/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: Double pointer to head of list
 * Return: 0 if it is not a palindrome 1 if it is a palindrome.
 */

int is_palindrome(listint_t **head)
{
	return (rec_pal(head, *head));

}
