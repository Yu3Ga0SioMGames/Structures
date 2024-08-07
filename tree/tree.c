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

void print_tree_node(TreeNode *tree_node)
{
    if(tree_node != NULL) {
        print_tree_node_(tree_node);
    } else {
        container_error = CONTAINER_NOT_PROVIDED;
    }
}

void insert_tree_node(TreeNode **tree_node, int64_t input_data)
{
    TreeNode **current_ptr = tree_node;

    if(current_ptr == NULL) {
        container_error = CONTAINER_NOT_PROVIDED;
        return;
    }

    TreeNode *new_tree_node = create_tree_node(input_data);

    while(*current_ptr != NULL) {
        if(input_data < (*current_ptr)->data) {
            current_ptr = &((*current_ptr)->left);
        } else {
            current_ptr = &((*current_ptr)->right);
        }
    }

    *current_ptr = new_tree_node;
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
