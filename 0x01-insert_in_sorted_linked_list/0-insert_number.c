#include "lists.h"
/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: head of the node.
 * @number: Number to insert into a sorted singly linked list.
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *tmp = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if ((*head == NULL) || (*head)->n >= new->n)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		tmp = *head;
		while (tmp->next != NULL && tmp->next->n < new->n)
		{
			tmp = tmp->next;
		}
		new->next = tmp->next;
		tmp->next = new;
	}
	return (new);
}
