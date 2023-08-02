#include "binary_trees.h"

/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: return 1 if perfect, otherwise return 0.
 * If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, no_of_leaves, i, power_of_2;

	if (tree)
	{
		height = binary_tree_height(tree);
		no_of_leaves = binary_tree_leaves(tree);
		power_of_2 = 1;
		for (i = 1; i <= height; i++)
			power_of_2 *= 2;
		if (power_of_2 == no_of_leaves)
			return (1);
	}
<<<<<<< HEAD
	return (binary_tree_is_perfect(tree->left) && (binary_tree_is_perfect(tree->right)));
=======
	return (0);
>>>>>>> 2bbef95a58e6d6034b7cff4e8a42d06c878d846c
}

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
