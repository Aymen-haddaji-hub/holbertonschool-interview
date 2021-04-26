#include "lists.h"
/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: head of the node.
 * @number: Number to insert into a sorted singly linked list.
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *root;
	listint_t *temp = *head;

	root = malloc(sizeof(listint_t));
	if (root == NULL)
		return (NULL);

	root->n = number;
	root->next = NULL;

	if ((*head == NULL) || (*head)->n >= root->n)
	{
		root->next = *head;
		*head = root;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL && temp->next->n < root->n)
		{
			temp = temp->next;
		}
		root->next = temp->next;
		temp->next = root;
	}
	return (root);
}
