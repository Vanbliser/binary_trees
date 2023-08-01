#include "binary_trees.h"

/**
 * binary_tree_leaves - a function that counts the leaves in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of leaves
 *
 * Return: returns the number of leaves. If tree is NULL, the function must
 * return 0. A NULL pointer is not a leaf.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left, right, leaves;

	if (tree)
	{
		left = binary_tree_leaves(tree->left);
		right = binary_tree_leaves(tree->right);
		leaves = left + right;
		if (leaves)
			return (leaves);
		else
			return (1);
	}
	return (0);
}
