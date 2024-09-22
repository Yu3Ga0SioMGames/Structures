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

void insert_tree_node(TreeNode **root, TreeNode *node)
{
	TreeNode **current_ptr = root;

	if(current_ptr == NULL) {
		container_error = CONTAINER_NOT_PROVIDED;

		return;
	}

	if(node == NULL) {
		return;
	}

	while(*current_ptr != NULL) {
		if(node->data < (*current_ptr)->data) {
			current_ptr = &((*current_ptr)->left);
		} else {
			current_ptr = &((*current_ptr)->right);
		}
	}

	*current_ptr = node;

	balancing_tree_node(root);
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

	balancing_tree_node(tree_node);
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

void balancing_tree_node(TreeNode **root)
{
	if(*root == NULL) {
		return;
	}

	int balance_factor = get_balance_factor(*root);

	if(balance_factor > 1) {
		if(get_balance_factor((*root)->left) < 0) {
			(*root)->left = rotate_left_tree_node((*root)->left);
		}
		*root = rotate_right_tree_node(*root);
	} else if(balance_factor < -1) {
		if(get_balance_factor((*root)->right) > 0) {
			(*root)->right = rotate_right_tree_node((*root)->right);
		}
		*root = rotate_left_tree_node(*root);
	}

	balancing_tree_node(&((*root)->left));
	balancing_tree_node(&((*root)->right));
}

int get_balance_factor(TreeNode *node)
{
	if(node == NULL) {
		return 0;
	}

	return get_height(node->left) - get_height(node->right);
}

int get_height(TreeNode *node)
{
	if(node == NULL) {
		return 0;
	}

	int left_height = get_height(node->left);
	int right_height = get_height(node->right);

	if(left_height > right_height) {
		return 1 + left_height;
	} else {
		return 1 + right_height;
	}
}
