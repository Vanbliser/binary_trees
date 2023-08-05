#include "binary_trees.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	bst_t *root;
	int array[] = {
		98, 110, 43, 56, 2, 78, 123, 76, 234
	};
	size_t size = sizeof(array) / sizeof(array[0]);

	root = array_to_bst(array, size);
	binary_tree_print(root);

	root = bst_remove(root, 98);
	binary_tree_print(root);

	binary_tree_delete(root);
	return (0);
}
