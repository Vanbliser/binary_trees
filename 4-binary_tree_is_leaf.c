#include "binary_trees.h"

/**
 * binary_tree_is_leaf - a function that checks if a node is a leaf
 * @node: a pointer to the node to check
 *
 * Description: If node is NULL, return 0
 * Return: return 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	else if (node->left)
		return (0);
	else if (node->right)
		return (0);
	else
		return (1);
}
