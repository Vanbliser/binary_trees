#include "binary_trees.h"

/**
 * binary_tree_is_bst - a function that checks if a binary tree is a valid
 * Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: return 1 if tree is a valid BST, and 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	list_t *list = NULL;

	if (tree)
	{
		convert_to_list_inorder(tree, &list);
		if (is_sorted_list_no_duplicate(list))
		{
			free_list(list);
			return (1);
		}
		free_list(list);
	}
	return (0);
}

/**
 * is_sorted_list_no_duplicate - a function that sorts a list_t
 * @head: pointer to the head of the list
 *
 * Return: returns 1 is sorted, otherwise return 0
 */
int is_sorted_list_no_duplicate(list_t *head)
{
	if (head)
	{
		while (head->next)
		{
			if (head->n >= head->next->n)
				return (0);
			head = head->next;
		}
		return (1);
	}
	return (0);
}

/**
 * convert_to_list_inorder - a function that converts a binary tree into a list
 * @tree: the binary tree to convert
 * @list: double pointer to the created list
 */
void convert_to_list_inorder(const binary_tree_t *tree, list_t **list)
{
	if (tree)
	{
		convert_to_list_inorder(tree->left, list);
		appendtolist(list, tree->n);
		convert_to_list_inorder(tree->right, list);
	}
}

/**
 * appendtolist - a function that appends to a list
 * @head: the head of the list to append to
 * @n: the new value to append to the end of the list
 */
void appendtolist(list_t **head, int n)
{
	list_t *new, *save_head;

	if (head)
	{
		new = malloc(sizeof(list_t));
		if (new)
		{
			new->n = n;
			new->next = NULL;
		}
		if (*head)
		{
			save_head = *head;
			while ((*head)->next)
				*head = (*head)->next;
			(*head)->next = new;
			*head = save_head;
		}
		else
		{
			*head = new;
		}
	}
}

/**
 * free_list - a function that frees a list
 * @head: the head of the list to free
 */
void free_list(list_t *head)
{
	list_t *tmp;

	if (head)
	{
		while (head->next)
		{
			tmp = head;
			head = head->next;
			free(tmp);
		}
		free(head);
	}
}
