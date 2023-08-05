#include "binary_trees.h"
#include <stdio.h>

/**
 * bst_remove - a function that removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Description: Once located, the node containing a value equals to value must
 * be removed and freed. If the node to be deleted has two children, it must be
 * replaced with its first in-order successor (not predecessor).
 * Return: return a pointer to the new root node of the tree after removing the
 * desired value.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *replace;

	if (root)
	{
		node = bst_search((const bst_t *)root, value);
		if (node)
		{
			printf("\nSTART\n\n");
			binary_tree_print(root);
			replace = replace_node(node);
			printf("1: root=%d, node=%d, replace=%d\n", root->n, node->n, replace->n);
			binary_tree_print(root);
			/* redirect nodes->children->parent to replace if they exist */
			if (node->left)
				node->left->parent = replace;
			if (node->right)
				node->right->parent = replace;
			printf("2\n");
			binary_tree_print(root);
			/* equate replace->children to nodes->children */
			replace->left = node->left;
			replace->right = node->right;
			replace->parent = node->parent;
			printf("3\n");
			binary_tree_print(root);
			/* point replace->parent->children to NULL, if they exist */
			if (replace->parent)
			{
				if (replace == replace->parent->left)
					replace->parent->left = NULL;
				else
					replace->parent->right = NULL;
			}
			printf("4\n");
			binary_tree_print(root);
			if (node == root && node != replace)
				root = replace;
			if (node == root && node == replace)
				root = NULL;
			printf("5\n");
			binary_tree_print(root);
			printf("6\n");
			binary_tree_print(root);
			printf("root=%d, left=%d, right=%d\n", root->n, root->left->n, root->right->n);
			binary_tree_print(root);
			free(node);
			printf("\n\nSTOP\n");
			return (root);
		}
	}
	return (NULL);
}

/**
 * replace_node - a function that locates the node to replace another node in
 * a binary search tree.
 * @node: pointer to the node to finds its replace node
 *
 * Return: the replace node
 */
bst_t *replace_node(const bst_t *node)
{
	bst_t *current, *parent;

	if (node)
	{
		if (node->right)
		{
			current = node->right;
			while (current)
			{
				parent = current;
				current = current->left;
			}
			return (parent);
		}
		else if (node->left)
		{
			current = node->left;
			while (current)
			{
				parent = current;
				current = current->right;
			}
			return (parent);
		}
		else
		{
			current = (bst_t *)node;
			return (current);
		}
	}
	return (NULL);
}

/**
 * bst_search - a function that searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 *
 * Return: return a pointer to the node containing a value equals to value.
 * If tree is NULL or if nothing is found, your function must return NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *current = (bst_t *)tree;

	if (tree)
	{
		while (current)
		{
			if (value == current->n)
				return (current);
			else if (value < current->n)
				current = current->left;
			else
				current = current->right;
		}
	}
	return (NULL);
}
