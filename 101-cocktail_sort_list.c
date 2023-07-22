#include "sort.h"

/**
 * swap_list - swap the nodes of a list
 * @list: the list to swap it's nodes
 * @n1: the first node to be swapped
 * @n2: the second node to be swapped
 * Return: 0, 1
*/
int swap_list(listint_t *n1, listint_t *n2, listint_t **list)
{
	int swapped = 0;

	if (n1->n > n2->n)
	{
		if (n1->prev != NULL)
			n1->prev->next = n2;
		else
			*list = n2;
		if (n2->next != NULL)
			n2->next->prev = n1;
		n1->next = n2->next;
		n2->prev = n1->prev;
		n1->prev = n2;
		n2->next = n1;
		print_list(*list);
		swapped = 1;
	}
	return (swapped);
}

/**
 * cocktail_sort_list - sort a doubly linked list using cocktail sort algorithm
 * @list: the list to be sorted
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped = 0;
	listint_t *node = *list, *tail = *list;

	if (!list || !*list || !(*list)->next)
		return;

	while (!swapped)
	{
		swapped = 1;
		for (node = (*list)->next; node; node = node->next)
		{
			if (swap_list(node->prev, node, list))
				swapped = 0;
			tail = node;
		}
		if (swapped)
			break;
		for (node = tail->prev; node; node = node->prev)
		{
			if (swap_list(node, node->next, list))
				swapped = 0;
		}
	}
}
