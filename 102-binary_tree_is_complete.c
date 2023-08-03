#include "binary_trees.h"

/**
 * binary_tree_is_complete- checks if a binary tree is complete
 * @tree: pointer to tree node
 *
 * Return: 0 if tree is null
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);
	size = n_nodes(tree);
	return (check_complete(tree, 0, size));
}


/**
 * n_nodes- measures size of binary tree (nodes)
 * @tree: pointer to tree node
 *
 * Return: 0 if tree is null
 */

size_t n_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + n_nodes(tree->left) + n_nodes(tree->right));
}


/**
 * check_complete- helpert function to checks if a binary tree is complete
 * @tree: pointer to tree node
 * @index: index of left  and right subtreees
 * @size: size of binary tree
 *
 * Return: 1 if tree is null and 0 if index > size
 */


int check_complete(const binary_tree_t *tree, unsigned int index, size_t size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);
	return (check_complete(tree->left, 2 * index + 1, size) &&
			check_complete(tree->right, 2 * index + 2, size));
}
