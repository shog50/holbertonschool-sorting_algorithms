#include "sort.h"
#include <stdio.h>

/**
* insertion_sort_list - Sorts a doubly linked list
* of integers in ascending order using the Insertion Sort algorithm.
* @list: Double pointer to the head of the doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *temp, *swap;

if (!list || !(*list) || !(*list)->next)
return;

current = (*list)->next;
while (current)
{
temp = current->prev;
swap = current;
while (temp && swap->n < temp->n)
{
if (temp->prev)
temp->prev->next = swap;
if (swap->next)
swap->next->prev = temp;
swap->prev = temp->prev;
temp->next = swap->next;
swap->next = temp;
temp->prev = swap;

if (!swap->prev)
*list = swap;

print_list(*list);

temp = swap->prev;
}
current = current->next;
}
}

