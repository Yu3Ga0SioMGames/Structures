#include "test.h"

int test()
{
	TreeNode *tree_node = NULL;

	tree_node = create_tree_node(15);
	tree_node->left = create_tree_node(13);
	tree_node->right = create_tree_node(17);
	tree_node->left->left = create_tree_node(12);
	tree_node->left->right = create_tree_node(14);
	tree_node->right->left = create_tree_node(16);
	tree_node->right->right = create_tree_node(18);

	printf("\n");
	print_tree_node(tree_node);
	printf("\n");


	printf("\n");
	insert_tree_value(&tree_node, 11);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	insert_tree_value(&tree_node, 12);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	insert_tree_value(&tree_node, 13);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	insert_tree_value(&tree_node, 14);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	insert_tree_value(&tree_node, 15);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	insert_tree_value(&tree_node, 16);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	insert_tree_value(&tree_node, 17);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	insert_tree_value(&tree_node, 18);
	print_tree_node(tree_node);
	printf("\n");


	printf("\n\n");
	TreeNode *result = NULL;
	result = find_tree_node(tree_node, 10);
	if(result != NULL) {
		printf("%ld", result->data);
	}
	printf("\n");

	printf("\n");
	result = find_tree_node(tree_node, 11);
	printf("%ld", result->data);
	printf("\n");

	printf("\n");
	result = find_tree_node(tree_node, 12);
	printf("%ld", result->data);
	printf("\n");

	printf("\n");
	result = find_tree_node(tree_node, 13);
	printf("%ld", result->data);
	printf("\n");

	printf("\n");
	result = find_tree_node(tree_node, 14);
	printf("%ld", result->data);
	printf("\n");

	printf("\n");
	result = find_tree_node(tree_node, 15);
	printf("%ld", result->data);
	printf("\n");

	printf("\n");
	result = find_tree_node(tree_node, 16);
	printf("%ld", result->data);
	printf("\n");

	printf("\n");
	result = find_tree_node(tree_node, 17);
	printf("%ld", result->data);
	printf("\n");

	printf("\n");
	result = find_tree_node(tree_node, 18);
	printf("%ld", result->data);
	printf("\n");

	printf("\n");
	result = find_tree_node(tree_node, 19);
	if(result != NULL) {
		printf("%ld", result->data);
	}
	printf("\n");


	remove_tree_node(&tree_node, 14);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	remove_tree_node(&tree_node, 0);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	remove_tree_node(&tree_node, 22);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	remove_tree_node(&tree_node, 18);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	remove_tree_node(&tree_node, 17);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	remove_tree_node(&tree_node, 16);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	remove_tree_node(&tree_node, 15);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	remove_tree_node(&tree_node, 13);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	remove_tree_node(&tree_node, 12);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	remove_tree_node(&tree_node, 12);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	remove_tree_node(&tree_node, 11);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	remove_tree_node(&tree_node, 12);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	remove_tree_node(&tree_node, 13);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	remove_tree_node(&tree_node, 14);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	remove_tree_node(&tree_node, 15);
	print_tree_node(tree_node);
	printf("\n");


	printf("\n");
	TreeNode *r = NULL;
	r = rotate_left_tree_node(tree_node);
	print_tree_node(tree_node);
	printf("\n");

	printf("\n");
	r = rotate_right_tree_node(tree_node);
	print_tree_node(tree_node);


	printf("\n\n");
	free_tree_node(tree_node);
	return 0;
}
