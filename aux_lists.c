#include "main.h"

/**
 * add_sept_node - appends a separator node to the end
 * of a sept_lists.
 * @head: pointer to the head of the linked lists.
 * @sept: separators char to add (; | &).
 * Return: address of the heads of the sep list.
 */
sep_list *add_sep_node(sep_list **head, char sept)
{
	sep_list *newNode, *tempNode;

	newNode = malloc(sizeof(sep_list));
	if (newNode == NULL)
		return (NULL);

	newNode->separator = sept;
	newNode->next = NULL;
	tempNode = *head;

	if (tempNode == NULL)
	{
		*head = newNode;
	}
	else
	{
		while (tempNode->next != NULL)
			tempNode = tempNode->next;
		tempNode->next = newNode;
	}

	return (*head);
}
