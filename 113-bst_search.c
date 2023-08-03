#include "binary_trees.h"

/**
 * bst_search - a function that searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 *
 * Return: return a pointer to the node containing a value equals to value.
 * If tree is NULL or if nothing is found, your function must return NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *current = (bst_t *)tree;

	if (tree)
	{
		while (current)
		{
			if (value == current->n)
				return (current);
			else if (value < current->n)
				current = current->left;
			else
				current = current->right;
		}
	}
	return (NULL);
}
