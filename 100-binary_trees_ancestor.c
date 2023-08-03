#include "binary_trees.h"

/**
 * binary_trees_ancestor- checks for lowest common ancestors
 * @first: pointer to first node
 * @second: pointer to second node
 *
 * Return: pointer to the lowest ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t f_d, s_d;

	if (!first || !second)
		return (NULL);
	f_d = binary_tree_depth(first->parent);
	s_d = binary_tree_depth(second->parent);

	if (first->right == second)
		return ((binary_tree_t *)first);

	if (second->left == first)
		return ((binary_tree_t *)second);
	return (f_d < s_d ? first->parent : second->parent);
}

/**
 * binary_tree_depth- checks depth of a tree in a binary tree
 * @tree: pointer to tree node
 *
 * Return: depth of tree or null on failure
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree)
	{
		depth = binary_tree_depth(tree->parent);
		if (tree->parent)
			return (1 + depth);
		else
			return (depth);
	}
	return (0);
}

