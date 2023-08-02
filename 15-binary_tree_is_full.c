#include "binary_trees.h"

/**
 * binary_tree_is_full- checks if binary tree is full
 * @tree: pointer to the tree node
 *
 * Return: 1 for full, 0for not full
 */

int binary_tree_is_full(const binary_tree_t *tree)
{

	int l, r;


	if (tree == NULL)
		return (0);


	l = binary_tree_is_full(tree->left);

	r = binary_tree_is_full(tree->right);

	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left && tree->right)
		return (l && r);

	return (0);
}
