#include "binary_trees.h"

/**
 * binary_tree_rotate_left- rotates a binary tree left
 * @tree: pointer to tree node
 *
 * Return: 0- if tree is null
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new;

	if (tree == NULL || tree->right == NULL)
		return (0);

	new = tree->right;

	new->parent = tree->parent;
	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = new;
		else
			tree->parent->right = new;
	}

	tree->right = new->left;
	if (new->left != NULL)
		new->left->parent = tree;

	new->left = tree;
	tree->parent = new;

	return (new);
}
