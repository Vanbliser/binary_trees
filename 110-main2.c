#include "binary_trees.h"

/**
 * print_list - a function to print the values in a list
 * @head: pointer to the head of the list
 */
void print_list(list_t *head)
{
	while (head)
	{
		printf("-%d-", head->n);
		head = head->next;
	}
	printf("\n");
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	list_t *list = NULL;
	binary_tree_t *root;

	appendtolist(&list, 1);
	appendtolist(&list, 2);
	appendtolist(&list, 3);
	appendtolist(&list, 3);
	appendtolist(&list, 5);
	appendtolist(&list, 6);
	print_list(list);
	if (is_sorted_list_no_duplicate(list))
		printf("sorted\n");
	else
		printf("not sorted\n");
	free_list(list);
	printf("\n==============================\n\n");
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 128);
	root->left->right = binary_tree_node(root->left, 54);
	root->right->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 10);
	binary_tree_print(root);
	list = NULL;
	convert_to_list_inorder(root, &list);
	print_list(list);
	if (is_sorted_list_no_duplicate(list))
		printf("sorted\n");
	else
		printf("not sorted\n");
	free_list(list);
	printf("\n==============================\n\n");
	binary_tree_print(root->left);
	list = NULL;
	convert_to_list_inorder(root->left, &list);
	print_list(list);
	if (is_sorted_list_no_duplicate(list))
		printf("sorted\n");
	else
		printf("not sorted\n");
	free_list(list);
	printf("\n==============================\n\n");
	root->right->left = binary_tree_node(root->right, 97);
	binary_tree_print(root);
	list = NULL;
	convert_to_list_inorder(root, &list);
	print_list(list);
	if (is_sorted_list_no_duplicate(list))
		printf("sorted\n");
	else
		printf("not sorted\n");
	free_list(list);
	binary_tree_delete(root);
	return (0);
}
