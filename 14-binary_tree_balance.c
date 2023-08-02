#include "binary_trees.h"

/**
 * binary_tree_balance - a function that measures the balance factor of a
 * binary tree. Balance factor of a tree is the height of the
 * left tree - height of right tree.
 * @tree: a pointer to the root node of the tree to measure the balance factor
 *
 * Return: returs 0 if tree is null
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (tree)
	{
		left = get_binary_tree_height(tree->left);
		left = (tree->left) ? left + 1 : left;
		right = get_binary_tree_height(tree->right);
		right = (tree->right) ? right + 1 : right;
		return (left - right);
	}
	return (0);
}

/**
 * get_binary_tree_height - a function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: returns the height of the tree.
 * If tree is NULL, your function must return 0
 */
int get_binary_tree_height(const binary_tree_t *tree)
{
	int left, right, height;

	if (tree)
	{
		left = get_binary_tree_height(tree->left);
		right = get_binary_tree_height(tree->right);
		height = (left >= right) ? left : right;
		if (tree->left || tree->right)
			return (height + 1);
		else
			return (height);
	}
	return (0);
}
