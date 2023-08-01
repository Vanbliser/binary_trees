#include "binary_trees.h"

/**
 * binary_tree_size - a function that measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 *
 * Return: returns the size of the tree.
 * If tree is NULL, the function must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree)
	{
		left = binary_tree_size(tree->left);
		right = binary_tree_size(tree->right);
		return (left + right + 1);
	}
	return (0);
}
