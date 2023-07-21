#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	int sorted = 0;
	listint_t *node, *node1, *node2;

	if (!list || !*list || !(*list)->next)
		return;
	while (!sorted)
	{
		sorted = 1;
		for (node = (*list)->next; node; node = node->next)
		{
			if (node->n < node->prev->n)
			{
				node1 = node->prev;
				node2 = node;
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
				print_list(*list);
				sorted = 0;
				break;
			}
		}
	}
}
