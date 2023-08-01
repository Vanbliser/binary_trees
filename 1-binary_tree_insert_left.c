#include "binary_trees.h"

/**
 * binary_tree_insert_left - a function that inserts a node as the left-child
 * of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: is the value to store in the new node
 *
 * Description: If parent already has a left-child, the new node must take its
 * place, and the old left-child must be set as the left-child of the new node.
 * Return: a pointer to the created node, or NULL on failure or if parent is
 * NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);
	node = malloc(sizeof(binary_tree_t) * 1);
	if (node == NULL)
		return (NULL);
	node->parent = parent;
	node->n = value;
	node->left = parent->left;
	if (node->left)
		node->left->parent = node;
	node->right = NULL;
	parent->left = node;
	return (node);
}
