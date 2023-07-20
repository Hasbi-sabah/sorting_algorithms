#include "sort.h"
void node_swapper(listint_t *node1, listint_t *node2, listint_t **list)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
void cocktail_sort_list(listint_t **list)
{
	int sorted = 0;
	listint_t *node, *tail;

	while (!sorted)
	{
		sorted = 1;
		for (node = (*list)->next; node; node = node->next)
		{
			if (node->n < node->prev->n)
			{
				node_swapper(node->prev, node, list);
				print_list(*list);
				sorted = 0;
			}
			tail = node;
		}
		if (sorted)
			break;
		for (node = tail->prev; node; node = node->prev)
		{
			if (node->n > node->next->n)
			{
				node_swapper(node, node->next, list);
				print_list(*list);
				sorted = 0;
			}

		}
	}
}
