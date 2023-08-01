#include "binary_trees.h"

/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: returns the height of the tree.
 * If tree is NULL, your function must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right, height;

	if (tree)
	{
		left = binary_tree_height(tree->left);
		right = binary_tree_height(tree->right);
		height = (left >= right) ? left : right;
		if (tree->left || tree->right)
			return (height + 1);
		else
			return (height);
	}
	return (0);
}
