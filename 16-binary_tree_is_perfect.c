#include "binary_trees.h"
/**
 * binary_tree_is_perfect- checks for a perfecr binary tree
 * @tree: pointer to tree node
 *
 * Return: 0 if perfect
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l_h, r_h;

	if (tree == NULL)
		return (0);





	l_h = binary_tree_height(tree->left);
	r_h = binary_tree_height(tree->right);

	if (l_h == r_h)
	{
		if (tree->left == NULL && tree->right == NULL)
			return (1);
		return (1);
	}
<<<<<<< HEAD
	return (binary_tree_is_perfect(tree->left) && (binary_tree_is_perfect(tree->right)));
=======
	return (0);
>>>>>>> 2bbef95a58e6d6034b7cff4e8a42d06c878d846c
}







/**
 * binary_tree_height- checks height of a binary tree
 * @tree: poinyer to tree node
 *
 * Return: 0 if tree is nill
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t r, l, height;

	if (tree)
	{
		r = binary_tree_height(tree->right);
		l = binary_tree_height(tree->left);
		height = (l >= r) ? l : r;
		return (height + 1);
	}

	return (0);
}
