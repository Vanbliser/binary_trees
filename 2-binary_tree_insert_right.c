#include "binary_trees.h"

/**
 * binary_tree_insert_right- a function that inserts a node as the right-child
 * of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 *
 * Description: If parent already has a right-child, the new node must take its
 * place and the old right-child be set as the right-child of the new node.
 * Return: return a pointer to the created node, or NULL on failure or if
 * parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);
	node = malloc(sizeof(binary_tree_t) * 1);
	if (node == NULL)
		return (NULL);
	node->parent = parent;
	node->n = value;
	node->left = NULL;
	node->right = parent->right;
	if (node->right)
		node->right->parent = node;
	parent->right = node;
	return (node);
}
