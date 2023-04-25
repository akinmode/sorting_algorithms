#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: input linked list
 * Return: prints ordered list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr = NULL, *tmp = NULL;
	int posswap = 1;

	if (!list || !(*list) || !(*list)->next)
		return;

	ptr = *list;
	while (ptr->next)
	{
		if (ptr->n > ptr->next->n)
		{
			ptr->next->prev = ptr->prev;
			if (ptr->next->prev)
				ptr->prev->next = ptr->next;
			else
				*list = ptr->next;

			ptr->prev = ptr->next;
			ptr->next = ptr->next->next;
			ptr->prev->next = ptr;
			if (ptr->next)
				ptr->next->prev = ptr;

			ptr = ptr->prev;
			print_list(*list);

			if (ptr->prev && ptr->prev->n > ptr->n)
			{
				if (!posswap)
					tmp = ptr->next;
				posswap = 1;
				ptr = ptr->prev;
				continue;
			}
		}
		if (!posswap)
			ptr = ptr->next;
		else
			ptr = tmp, posswap = 0;
	}
}
