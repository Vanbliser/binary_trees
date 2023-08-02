#include "binary_trees.h"


void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i, height;
	
	height = binary_tree_height(tree);

	for (i=0; i<height; i++)
	{
		for (
	}
}

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_h, r_h;

	if (tree == NULL)
		return (0);

	l_h = binary_tree_height(tree->left);
	r_h = binary_tree_height(tree->right);

	return max(l_h, r_h) + 1;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}
