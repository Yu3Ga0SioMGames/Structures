#include "test.h"

void test_01(TreeNode **tree_node);

void test_2(TreeNode **tree_node);

void test_3(TreeNode **tree_node);

int remove_test()
{
	TreeNode *root = NULL;
	for(int i = 0; i < 15; ++i) {
		insert_tree_value(&root, i);
	}
	print_tree_node2(root);
	printf("\n\n");
	print_tree_node(root);
	printf("\n\n");

	remove_tree_value(&root, 7);
	print_tree_node(root);
	printf("\n");

	for(int i = 0; i < 7; ++i) {
		remove_tree_value(&root, i);
		print_tree_node(root);
	}

	print_tree_node(root);

	free_tree_node(root);
	return 0;
}

int test()
{
	TreeNode *tree_node = NULL;

	test_01(&tree_node);
	print_tree_node(tree_node);
	tree_node == NULL;

	test_2(&tree_node);
	print_tree_node(tree_node);
	tree_node == NULL;

	test_3(&tree_node);
	print_tree_node(tree_node);
	tree_node == NULL;


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


	TreeNode *result = NULL;
	result = find_tree_node(tree_node, 10);
	if(result != NULL) {
		printf("%ld", result->data);
	}

	printf("\n\n");
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

	remove_tree_node(&tree_node, 15);
	print_tree_node(tree_node);


	TreeNode *r = NULL;
	r = rotate_left_tree_node(tree_node);
	print_tree_node(tree_node);

	r = rotate_right_tree_node(tree_node);
	print_tree_node(tree_node);


	free_tree_node(tree_node);
	return 0;
}

void test_01(TreeNode **tree_node)
{
	insert_tree_value(tree_node, 12);
	insert_tree_value(tree_node, 13);
	insert_tree_value(tree_node, 14);
	insert_tree_value(tree_node, 15);
	insert_tree_value(tree_node, 16);
	insert_tree_value(tree_node, 17);
	insert_tree_value(tree_node, 18);
}

void test_2(TreeNode **tree_node)
{
	insert_tree_value(tree_node, 18);
	insert_tree_value(tree_node, 17);
	insert_tree_value(tree_node, 16);
	insert_tree_value(tree_node, 15);
	insert_tree_value(tree_node, 14);
	insert_tree_value(tree_node, 13);
	insert_tree_value(tree_node, 12);
}

void test_3(TreeNode **tree_node)
{
	insert_tree_value(tree_node, 17);
	insert_tree_value(tree_node, 18);
	insert_tree_value(tree_node, 13);
	insert_tree_value(tree_node, 16);
	insert_tree_value(tree_node, 15);
	insert_tree_value(tree_node, 14);
	insert_tree_value(tree_node, 12);
}
