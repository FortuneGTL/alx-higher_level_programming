#include "lists.h"

/**
 * insert_node - inserts a number into a sorted list
 * @head: pointer to the list
 * @number: number to add
 * Return: address of the added node else NULL
 */
listint_t *insert_node(listint_t **head, int number)
{
  listint_t *old, *new, *current;

  if (head == NULL)
    return (NULL);

  new = malloc(sizeof(listint_t));
  if (new == NULL)
    return (NULL);

  new->n = number;
  old = NULL;
  current = *head;

  for (; current != NULL && current->n < number;)
    {
      old = current;
      current = current->next;
    }

  new->next = current;

  if (old != NULL)
    old->next = new;
  else
    *head = new;

  return (new);
}
#include <stdlib.h>

#include "lists.h"

/**

 * insert_node - inserts a number into a sorted singly linked list

 * @head: head of the linked list

 * @number: number value of the new node

 *

 * Return: new node or NULL if it fails

 */

listint_t *insert_node(listint_t **head, int number)

{

	listint_t *current, *next, *new;

	new = (listint_t *)malloc(sizeof(listint_t));

	if (new == NULL)

		return (NULL);

	new->n = number;

	if (head == NULL || *head == NULL)

	{

		*head = new;

		return (new);

	}

	current = *head;

	next = current->next;

	if (number < current->n)

	{

		new->next = current;

		*head = new;

		return (new);

	}

	while (number > next->n)

	{

		current = current->next;

		if (next->next == NULL)

		{

			current->next = new;

			return (new);

		}

		next = next->next;

	}

	new->next = next;

	current->next = new;

	return (new);

}
