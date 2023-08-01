#include "binary_trees.h"

/* binary_tree_nodes - a function that counts the nodes with at least 1 child
 * in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of nodes
 *
 * Return: return the result. If tree is NULL, the function must return 0
 * A NULL pointer is not a node
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left, right, non_leaves;

	if (tree)
	{
		left = binary_tree_nodes(tree->left);
		right = binary_tree_nodes(tree->right);
		non_leaves = left + right;
		if (tree->left || tree->right)
			non_leaves++;
		return (non_leaves);
	}
	return (0);
}
