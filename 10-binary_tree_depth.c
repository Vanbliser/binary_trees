#include "binary_trees.h"

/**
 * binary_tree_depth - a function that measures the depth of a node in a
 * binary tree
 * @tree: a pointer to the node to measure the depth
 *
 * Return: return the depth of the tree.
 * If tree is NULL, your function must return 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth_of_parent;

	if (tree)
	{
		depth_of_parent = binary_tree_depth(tree->parent);
		if (tree->parent)
			return (1 + depth_of_parent);
		else
			return (depth_of_parent);
	}
	return (0);
}
