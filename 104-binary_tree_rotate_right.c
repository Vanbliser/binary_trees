#include "binary_trees.h"

/**
 * binary_tree_rotate_right- rotates a binary tree right
 * @tree: pointer to tre node
 *
 * Return: pointer to tree
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	new = tree->left;

	new->parent = tree->parent;
	if (tree->parent)
	{
		if (tree->parent->left == tree)
			tree->parent->left = new;
		else
			tree->parent->right = new;
	}

	tree->left = new->right;
	if (new->right)
		new->right->parent = tree;

	new->right = tree;
	tree->parent = new;

	return (new);
}



