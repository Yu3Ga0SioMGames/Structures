#include "tree.h"

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

TreeNode **find_max_tree_node(TreeNode *);

TreeNode **find_min_tree_node(TreeNode *);

TreeNode **find_replacement(TreeNode **, int *);

void print_tree_node2(TreeNode *tree_node)
{
	if(tree_node != NULL) {
		print_tree_node_2(tree_node->left, tree_node, 2);
		printf("\nRoot: %ld_%hhd_%d\n\n", tree_node->data, tree_node->balance_factor, 1);
		print_tree_node_2(tree_node->right, tree_node, 2);
		fflush(stdout);
	} else {
		container_error = CONTAINER_NOT_PROVIDED;
	}
}

void print_tree_node_(TreeNode *tree_node, int height)
{
	if(tree_node == NULL) {
		return;
	}

	print_tree_node_(tree_node->left, height + 1);
	printf("%ld_%hhd_%d  ", tree_node->data, tree_node->balance_factor, height);
	print_tree_node_(tree_node->right, height + 1);
}

void print_tree_node_2(TreeNode *current, TreeNode *parent, int height)
{
	if(current != NULL) {
		print_tree_node_2(current->left, current, height + 1);
		printf("%ld_%hhd_%d: %ld_%hhd_%d\n", parent->data, parent->balance_factor, height,
		       current->data, current->balance_factor, height + 1);
		print_tree_node_2(current->right, current, height + 1);
	}
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
		print_tree_node_(tree_node, 1);
		printf("\n\n");
		fflush(stdout);
	} else {
		container_error = CONTAINER_NOT_PROVIDED;
	}
}

int insert_tree_node(TreeNode **root, TreeNode *new_node)
{
	if (*root == NULL) {
		*root = new_node;
		return 1;
	}

	int old_factor = (*root)->balance_factor;

	if (new_node->data < (*root)->data) {
		int result = insert_tree_node(&(*root)->left, new_node);
		if (result == 1) {
			(*root)->balance_factor -= 1;
			if ((*root)->balance_factor < -1) {
				balance_tree_node(root);
			}
		}
	} else {
		int result = insert_tree_node(&(*root)->right, new_node);
		if (result == 1) {
			(*root)->balance_factor += 1;
			if ((*root)->balance_factor > 1) {
				balance_tree_node(root);
			}
		}
	}

	return (*root)->balance_factor != 0 && old_factor == 0 ? 1 : 0;
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

int64_t remove_tree_node2(TreeNode **current, int64_t input_data)
{
	if(*current == NULL) {
		return CONTAINER_NOT_PROVIDED;
	}

	if(input_data == (*current)->data) {
		if((*current)->left == NULL && (*current)->right == NULL) {
			free_this_tree_node(*current);
			*current = NULL;

			return 1;
		} else if((*current)->left != NULL && (*current)->right != NULL) {
			TreeNode **replacement = find_min_tree_node((*current)->right);
			(*current)->data = (*replacement)->data;
			int64_t temp = remove_tree_node2(replacement, (*replacement)->data);
			if(temp == 1) {
				(*current)->balance_factor -= 1;
			}
		} else {
			TreeNode *child = (*current)->left != NULL ? (*current)->left : (*current)->right;
			free_this_tree_node(*current);
			*current = child;

			return 1;
		}
	} else {
		if(input_data < (*current)->data) {
			int result = remove_tree_node2(&((*current)->left), input_data);
			if(result == 1) {
				(*current)->balance_factor += 1;
				if((*current)->balance_factor > 1) {
					balance_tree_node(current);
				}
			}
		} else {
			int result = remove_tree_node2(&((*current)->right), input_data);
			if(result == 1) {
				(*current)->balance_factor -= 1;
				if((*current)->balance_factor < -1) {
					balance_tree_node(current);
				}
			}
		}
	}

	return (*current)->balance_factor != 0 ? 1 : 0;
}

void remove_tree_value(TreeNode **root, int64_t input_data)
{
	if(*root == NULL) {
		container_error = CONTAINER_NOT_PROVIDED;

		return;
	}

	if((*root)->data == input_data) {
		int side;
		TreeNode **replacement = find_replacement(root, &side);
		if(replacement != NULL) {
			(*root)->data = (*replacement)->data;
			int64_t temp = remove_tree_node2(replacement, (*replacement)->data);
			*replacement = NULL;
		} else {
			free_this_tree_node(*root);
			*root = NULL;

			return 1;
		}
	} else if(input_data < (*root)->data) {
		int64_t temp = remove_tree_node2(&((*root)->left), input_data);
		if(temp == 1) {
			(*root)->balance_factor += 1;
			if((*root)->balance_factor > 1) {
				balance_tree_node(root);
			}
		}
	} else {
		int64_t temp = remove_tree_node2(&((*root)->right), input_data);
		if(temp == 1) {
			(*root)->balance_factor -= 1;
			if((*root)->balance_factor < -1) {
				balance_tree_node(root);
			}
		}
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

	TreeNode *maximum_parent = find_max_tree_node(current->left);

	if(maximum_parent != NULL) {
		current->data = maximum_parent->right->data;
		TreeNode *max_temp = maximum_parent->right;
		maximum_parent->right = maximum_parent->right->left;
		max_temp->left = NULL;
		free_this_tree_node(max_temp);
		maximum_parent->balance_factor -= 1;
	} else if(parent != NULL) {
		free_this_tree_node(current);
		if(input_data < parent->data) {
			parent->left = NULL;
		} else {
			parent->right = NULL;
		}
	}
}

TreeNode **find_max_tree_node(TreeNode *root)
{
	if(root == NULL) {
		container_error = CONTAINER_NOT_PROVIDED;

		return NULL;
	}

	TreeNode *tmp = root;
	while(tmp->right != NULL) {
		if(tmp->right->right == NULL) {
			return &(tmp->right);
		}

		tmp = tmp->right;
	}

	return &tmp;
}

TreeNode **find_min_tree_node(TreeNode *root)
{
	if(root == NULL) {
		container_error = CONTAINER_NOT_PROVIDED;

		return NULL;
	}

	TreeNode *tmp = root;
	while(tmp->left != NULL) {
		if(tmp->left->left == NULL) {
			return &(tmp->left);
		}

		tmp = tmp->left;
	}

	return &tmp;
}

TreeNode **find_replacement(TreeNode **root, int *side)
{
	if(root == NULL) {
		container_error = CONTAINER_NOT_PROVIDED;

		return NULL;
	}

	if((*root)->left != NULL) {
		TreeNode **tmp = find_max_tree_node((*root)->left);
		if(tmp != NULL) {
			*side = -1;

			return tmp;
		}
	} else if((*root)->right != NULL) {
		TreeNode **tmp = find_min_tree_node((*root)->right);
		if(tmp != NULL) {
			*side = 1;

			return tmp;
		}
	}

	*side = 0;

	return NULL;
}

void update_height(TreeNode * tree_node)
{
	if(tree_node != NULL) {
		tree_node->balance_factor = 1 + max(get_balance_factor(tree_node->left), get_balance_factor(tree_node->right));
	}
}

int get_balance_factor(TreeNode * node)
{
	if(node == NULL) {
		return 0;
	}

	return node->balance_factor;
}

TreeNode *rotate_left_tree_node(TreeNode *root)
{
	TreeNode *new_root = root->right;
	root->right = new_root->left;
	new_root->left = root;

	root->balance_factor = root->balance_factor - 1 - max(0, new_root->balance_factor);
	new_root->balance_factor = new_root->balance_factor - 1 + min(0, root->balance_factor);

	return new_root;
}

TreeNode *rotate_right_tree_node(TreeNode *root)
{
	TreeNode *new_root = root->left;
	root->left = new_root->right;
	new_root->right = root;

	root->balance_factor = root->balance_factor + 1 - min(0, new_root->balance_factor);
	new_root->balance_factor = new_root->balance_factor + 1 + max(0, root->balance_factor);

	return new_root;
}

void balance_tree_node(TreeNode **root)
{
	if(*root == NULL) {
		return;
	}

	if((*root)->balance_factor > 1) {
		if((*root)->right->balance_factor < 0) {
			(*root)->right = rotate_right_tree_node((*root)->right);
		}

		*root = rotate_left_tree_node(*root);
	} else if((*root)->balance_factor < -1) {
		if((*root)->left->balance_factor > 0) {
			(*root)->left = rotate_left_tree_node((*root)->left);
		}

		*root = rotate_right_tree_node(*root);
	}
}
