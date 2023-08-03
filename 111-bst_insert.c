#include "binary_trees.h"

/**
 * bst_insert - a function that inserts a value in a Binary Search Tree
 * @tree: is a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Description: If the address stored in tree is NULL,
 * the created node must become the root node.
 * If the value is already present in the tree, it must be ignored
 * Return: return a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *parent, *current;

	if (tree)
	{
		current = *tree;
		parent = current;
		while (current)
		{
			parent = current;
			if (value == current->n)
				return (NULL);
			else if (value < current->n)
				current = current->left;
			else
				current = current->right;
		}
		new = binary_tree_node(parent, value);
		if (parent)
		{
			if (new->n < parent->n)
				parent->left = new;
			else
				parent->right = new;
		}
		else
		{
			*tree = new;
		}
		return (new);
	}
	return (NULL);
}
