#include "binary_trees.h"


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
			replace = replace_node(node);
			if (node == replace)
			{
				free(node);
				return (NULL);
			}
			node->n = replace->n;
			if (replace->parent)
			{
				if (replace == replace->parent->left)
					replace->parent->left = NULL;
				if (replace == replace->parent->right)
					replace->parent->right = NULL;
			}
			free(replace);
		}
	}
	return (root);
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
