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

/**
 * free_sep_list - frees a separator lists
 * @head: pointer to the head of the linked lists.
 * Return: null.
 */

void free_sep_list(sep_list **head)
{
	sep_list *tempNode;
	sep_list *currNode;

	if (head != NULL)
	{
		currNode = *head;
		while ((tempNode = currNode) != NULL)
		{
			currNode = currNode->next;
			free(tempNode);
		}
		*head = NULL;
	}
}

/**
 * add_line_node_end - appends a command line at the end
 * of a line_lists.
 * @head: pointer to the head of the linked lists.
 * @line: command lines string to add.
 * Return: address of the heads.
 */
line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *newNode, *tempNode;

	newNode = malloc(sizeof(line_list));
	if (newNode == NULL)
		return (NULL);

	newNode->line = line;
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

/**
 * free_line_list - frees a line_lists
 * @head: pointer to the heads of the linked lists.
 * Return: NULL
 */
void free_line_list(line_list **head)
{
	line_list *tempNode;
	line_list *currNode;

	if (head != NULL)
	{
		currNode = *head;
		while ((tempNode = currNode) != NULL)
		{
			currNode = currNode->next;
			free(tempNode);
		}
		*head = NULL;
	}
}
