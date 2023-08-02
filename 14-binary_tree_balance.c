#include "binary_trees.h"

/**
 * binary_tree_balance- measures the balance factor of a binary tree
 * @tree: pointer to tree node
 *
 * Return: returs 0 if tree is null
 */



int binary_tree_balance(const binary_tree_t *tree)
{
	int l_h, r_h;

	if (tree == NULL)
		return (0);

	l_h = binary_tree_height(tree->left);
	r_h = binary_tree_height(tree->right);

	return (l_h - r_h);
}



/**
 * binary_tree_height- checks heiggt of a binary tree
 * @tree: pointer to the tree node
 *
 * Return: 0 when tree is null
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l, r, height;

	if (tree)
	{
		l = binary_tree_height(tree->left);
		r = binary_tree_height(tree->right);
		height = (l >= r) ? l : r;
		return (height + 1);
	}
	return (0);
}
