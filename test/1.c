#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list
 * @list: list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp, *next;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while(current)
	{
		temp = current;
		while(temp && temp->n < temp->prev->n)
		{
			prev = temp->prev;
			next = temp->next;

			temp->next = prev;
			temp->prev = prev->prev;
			prev->next = next;
			if (temp->prev)
				 temp->prev->next = temp;
			else
				(*list) = temp;

			if (next)
				next->prev = prev;

			temp = prev;
			print_list(*list);

		}
		current = current->next;
	}
}
