#include "test.h"

int test()
{
    TreeNode *tree_node = NULL;

    tree_node = create_tree_node(0);
    tree_node->left = create_tree_node(1);
    tree_node->right = create_tree_node(2);
    tree_node->left->left = create_tree_node(3);
    tree_node->left->right = create_tree_node(4);
    tree_node->right->left = create_tree_node(5);
    tree_node->right->right = create_tree_node(6);

    print_tree_node(tree_node);

    free_tree_node(tree_node);
    return 0;
}
