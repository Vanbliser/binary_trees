#include "binary_trees.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	/*int node, replace;*/
    bst_t *tree; /*, *r_node*/
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = array_to_bst(array, n);
    if (!tree)
        return (1);
    binary_tree_print(tree);
/*
	printf("\n\n==========================================\n\n");

	node = 87;
	r_node = replace_node(bst_search(tree, node));
	replace = r_node->n;
	printf("The replace node for %d is %d\n", node, replace);
	printf("==========================================\n");

	node = 84;
	r_node = replace_node(bst_search(tree, node));
	replace = r_node->n;
	printf("The replace node for %d is %d\n", node, replace);
	printf("==========================================\n");

	node = 68;
	r_node = replace_node(bst_search(tree, node));
	replace = r_node->n;
	printf("The replace node for %d is %d\n", node, replace);
	printf("==========================================\n");

	node = 32;
	r_node = replace_node(bst_search(tree, node));
	replace = r_node->n;
	printf("The replace node for %d is %d\n", node, replace);
	printf("==========================================\n");

	node = 21;
	r_node = replace_node(bst_search(tree, node));
	replace = r_node->n;
	printf("The replace node for %d is %d\n", node, replace);
	printf("==========================================\n");

	node = 79;
	r_node = replace_node(bst_search(tree, node));
	replace = r_node->n;
	printf("The replace node for %d is %d\n", node, replace);
	printf("==========================================\n");

	node = 47;
	r_node = replace_node(bst_search(tree, node));
	replace = r_node->n;
	printf("The replace node for %d is %d\n", node, replace);
	printf("==========================================\n");
*/
	tree = bst_remove(tree, 47);
    binary_tree_print(tree);

	tree = bst_remove(tree, 79);
    binary_tree_print(tree);

	tree = bst_remove(tree, 21);
    binary_tree_print(tree);

	tree = bst_remove(tree, 32);
    binary_tree_print(tree);

	return (0);
}
