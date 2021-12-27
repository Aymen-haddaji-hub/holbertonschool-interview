#include "list.h"

/**
 * add_node_end - Adds a new node to the end of a double circular linked list
 * @list: A pointer to the head of the list
 * @str: The string to be added to the new node
 *
 * Return: A pointer to the new node
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *tmp;

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);
	new_node->str = strdup(str);
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*list == NULL)
	{
		*list = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		return (new_node);
	}
	tmp = *list;
	while (tmp->next != *list)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->prev = tmp;
	new_node->next = *list;
	(*list)->prev = new_node;
	return (new_node);
}
/**
 * add_node_begin - Adds a new node to the beginning of a
 * double circular linked list
 * @list: A pointer to the head of the list
 * @str: The string to be added to the new node
 *
 * Return: A pointer to the new node
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node = add_node_end(list, str);

	if (new_node == NULL)
		return (NULL);
	*list = new_node;
	return (new_node);
}
