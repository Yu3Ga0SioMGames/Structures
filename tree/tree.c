#include "tree.h"

void print_tree_node_(TreeNode *tree_node)
{
	print_tree_node(tree_node->left);
	printf("%ld ", tree_node->data);
	print_tree_node(tree_node->right);
}

TreeNode *create_tree_node(int64_t input_data)
{
	TreeNode *tree_node = (TreeNode *)malloc(sizeof(TreeNode));
	if(tree_node == NULL) {
		return NULL;
	}

	tree_node->data = input_data;
	tree_node->balance_factor = 0;
	tree_node->left = NULL;
	tree_node->right = NULL;

	return tree_node;
}

void free_tree_node(TreeNode *tree_node)
{
	if(tree_node != NULL) {
		free_tree_node(tree_node->right);
		free_tree_node(tree_node->left);
		free(tree_node);
	} else {
		container_error = CONTAINER_NOT_PROVIDED;
	}
}

void free_this_tree_node(TreeNode *tree_node)
{
	if(tree_node != NULL) {
		free(tree_node);
	} else {
		container_error = CONTAINER_NOT_PROVIDED;
	}
}

void print_tree_node(TreeNode *tree_node)
{
	if(tree_node != NULL) {
		print_tree_node_(tree_node);
	} else {
		container_error = CONTAINER_NOT_PROVIDED;
	}
}

void insert_tree_node(TreeNode **root, TreeNode *new_node)
{
	TreeNode **current_ptr = root;

	if(current_ptr == NULL) {
		container_error = CONTAINER_NOT_PROVIDED;

		return;
	}

	if((*current_ptr) == NULL) {
		(*current_ptr) = new_node;

		return;
	}

	if(new_node == NULL) {
		container_error = CONTAINER_IS_EMPTY;

		return;
	}

	if(new_node->data < (*current_ptr)->data) {
		insert_tree_node(&(*current_ptr)->left, new_node);
	} else {
		insert_tree_node(&(*current_ptr)->right, new_node);
	}
}

void insert_tree_value(TreeNode **tree_node, int64_t input_data)
{
	TreeNode **current_ptr = tree_node;

	if(current_ptr == NULL) {
		container_error = CONTAINER_NOT_PROVIDED;

		return;
	}

	TreeNode *new_tree_node = create_tree_node(input_data);

	insert_tree_node(tree_node, new_tree_node);
}

TreeNode *find_tree_node(TreeNode *tree_node, int64_t input_data)
{
	if(tree_node == NULL || tree_node->data == input_data) {
		return tree_node;
	}

	if(input_data < tree_node->data) {
		return find_tree_node(tree_node->left, input_data);
	} else {
		return find_tree_node(tree_node->right, input_data);
	}
}

void remove_tree_node(TreeNode **tree_node, int64_t input_data)
{
	if(*tree_node == NULL) {
		container_error = CONTAINER_NOT_PROVIDED;

		return;
	}

	TreeNode *current = *tree_node;
	TreeNode *parent = NULL;

	while(current != NULL && current->data != input_data) {
		parent = current;
		if(input_data < current->data) {
			current = current->left;
		} else {
			current = current->right;
		}
	}

	if(current == NULL) {
		return;
	}

	TreeNode **insert_place = NULL;

	if(parent != NULL) {
		if(input_data < parent->data) {
			parent->left = NULL;
		} else {
			parent->right = NULL;
		}
		insert_place = &parent;
	} else {
		*tree_node = NULL;
		insert_place = tree_node;
	}

	insert_tree_node(insert_place, current->left);
	insert_tree_node(insert_place, current->right);

	free_this_tree_node(current);
}

TreeNode *rotate_left_tree_node(TreeNode *root)
{
	if(root == NULL) {
		container_error = CONTAINER_NOT_PROVIDED;

		return root;
	}

	TreeNode *new_root = root->right;
	if(new_root == NULL) {
		return root;
	}

	root->right = new_root->left;
	new_root->left = root;

	return new_root;
}

TreeNode *rotate_right_tree_node(TreeNode *root)
{
	if(root == NULL) {
		container_error = CONTAINER_NOT_PROVIDED;

		return root;
	}

	TreeNode *new_root = root->left;
	if(new_root == NULL) {
		return root;
	}

	root->left = new_root->right;
	new_root->right = root;

	return new_root;
}

/*void balance_tree_node(TreeNode **root)
{
	if(*root == NULL) {
		container_error = CONTAINER_NOT_PROVIDED;

		return;
	}

	int8_t balance_factor = *root->balance_factor;
}*/

int get_balance_factor(TreeNode *node)
{
	if(node == NULL) {
		return 0;
	}

	return node->balance_factor;
}
