#include "sort.h"
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);
void insertion_sort_list(listint_t **list);
/**
 * swap_nodes - swaps two consecutive nodes in a doubly linked
 * list
 * @h: points to the head of the provided doubly linked list
 * @n1: points to the first node that should be swapped
 * @n2: the second node that should be swapped
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - uses the insertion sort algorithm to
 * sort a doubly linked list of integers
 * @list: the linked dlist that should be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *present, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (present = (*list)->next; present != NULL; present = tmp)
	{
		tmp = present->next;
		insert = present->prev;

		while (insert != NULL && present->n < insert->n)
		{
			swap_nodes(list, &insert, present);
			print_list((const listint_t *)*list);
		}
	}
}
