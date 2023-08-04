#include "binary_trees.h"
#include <stdio.h>

int main(void)
{
    binary_tree_t *root, *parent;
	size_t nth, depth;
	int value, node;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    root->left->right = binary_tree_node(root->left, 54);
    root->right->right = binary_tree_node(root->right, 128);
    root->left->left = binary_tree_node(root->left, 10);
    root->right->left = binary_tree_node(root->right, 45);
    root->right->right->left = binary_tree_node(root->right->right, 92);
    root->right->right->right = binary_tree_node(root->right->right, 65);
    binary_tree_print(root);

	nth = 2;
	parent = find_parent(root->right->right->left, nth);
	node = root->right->right->left->n;
	value = parent->n;
	depth = binary_tree_depth(root->right->right->left);
    printf("The %luth parent of %d is %d of depth %lu\n", nth, node, value, depth);

	printf("===========================================\n");
	nth = 2;
	parent = find_parent(root->left->right, nth);
	node = root->left->right->n;
	value = parent->n;
	depth = binary_tree_depth(root->left->right);
    printf("The %luth parent of %d is %d of depth %lu\n", nth, node, value, depth);

	printf("===========================================\n");
	nth = 1;
	parent = find_parent(root->left->left, nth);
	node = root->left->left->n;
	value = parent->n;
	depth = binary_tree_depth(root->left->left);
    printf("The %luth parent of %d is %d of depth %lu\n", nth, node, value, depth);

	printf("===========================================\n");
	nth = 1;
	parent = find_parent(root->right->left, nth);
	node = root->right->left->n;
	value = parent->n;
	depth = binary_tree_depth(root->right->left);
    printf("The %luth parent of %d is %d of depth %lu\n", nth, node, value, depth);

    return (0);
}
