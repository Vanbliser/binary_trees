#include "binary_trees.h"

/**
 * binary_tree_sibling- checks for a two nodes wih same parent
 * @node: pointer to chid node to find
 *
 * Return: null if node or parent is null
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{

	if (node == NULL || node->parent == NULL)
		return (NULL);


	if (node->parent->left == node)
		return (node->parent->right);


	return (node->parent->left);
}
