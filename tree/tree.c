#include "tree.h"

void print_tree_node_(TreeNode *tree_node)
{
    printf("%ld ", tree_node->data);
    print_tree_node(tree_node->left);
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

TreeNode *insert_tree_node(TreeNode *tree_node, int64_t input_data)
{
    if(tree_node == NULL) {
        return create_tree_node(input_data);
    }

    TreeNode *parent_tree_node = NULL;

    while(tree_node != NULL) {
        parent_tree_node = tree_node;

        if(input_data < tree_node->data) {
            tree_node = tree_node->left;
        } else {
            tree_node = tree_node->right;
        }
    }

    if(input_data < parent_tree_node->data) {
        parent_tree_node->left = create_tree_node(input_data);
    } else {
        parent_tree_node->right = create_tree_node(input_data);
    }

    return tree_node;
}

;
