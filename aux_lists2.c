#include "main.h"
/**
 * add_var_node - add a variable node at the end of a r_var list.
 * @head: pointer to the head of the linked list.
 * @l_var: length of the variable name
 * @val: value of the variable name
 * @l_val: length of the value
 * Return: address of the head.
 */
r_var *add_var_node(r_var **head, int l_var, char *val, int l_val)
{
	r_var *newNode, *tempNode;

	newNode = malloc(sizeof(r_var));
	if (newNode == NULL)
		return (NULL);

	newNode->len_var = l_var;
	newNode->val = val;
	newNode->len_val = l_val;

	newNode->next = NULL;
	tempNode = *head;

	if (tempNode == NULL)
	{
		*head = newNode;
	}
	else
	{
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;
		}
		tempNode->next = newNode;
	}
	return (*head);
}

/**
 * free_var_list - frees a r_var linked list.
 * @head: pointer to the head of the linked list.
 * Return: NULL
 */
void free_var_list(r_var **head)
{
	r_var *tempNode;
	r_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((tempNode = curr) != NULL)
		{
			curr = curr->next;
			free(tempNode);
		}
		*head = NULL;
	}
}
