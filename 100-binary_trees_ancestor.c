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
	size_t f_d, s_d, diff;
	binary_tree_t *f_current, *s_current;

	if (!first || !second)
		return (NULL);
	f_current = (binary_tree_t *)first;
	s_current = (binary_tree_t *)second;
	f_d = binary_tree_depth(first);
	s_d = binary_tree_depth(second);
	diff = (f_d >= s_d) ? f_d - s_d : s_d - f_d;
	if (f_d > s_d)
		f_current = find_parent(f_current, diff);
	if (f_d < s_d)
		s_current = find_parent(s_current, diff);

	while (f_current && s_current)
	{
		if (f_current == s_current)
			return (f_current);
		f_current = find_parent(f_current, 1);
		s_current = find_parent(s_current, 1);
	}
	return (NULL);
}

/**
 * find_parent - a function that finds the parent of a node up to the
 * nth generation.
 * @node: the node to find its parent.
 * @nth: the number of generation.
 *
 * Return: returns the found parent node
 */
binary_tree_t *find_parent(binary_tree_t *node, size_t nth)
{
	size_t i = 0;

	while (node && (i < nth))
	{
		node = node->parent;
		i++;
	}
	return (node);
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
