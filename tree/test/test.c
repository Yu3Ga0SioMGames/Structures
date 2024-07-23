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
    print_tree_node(tree_node);


    printf("\n");
    insert_tree_node(tree_node, 11);
    print_tree_node(tree_node);

    printf("\n");
    insert_tree_node(tree_node, 12);
    print_tree_node(tree_node);

    printf("\n");
    insert_tree_node(tree_node, 13);
    print_tree_node(tree_node);

    printf("\n");
    insert_tree_node(tree_node, 14);
    print_tree_node(tree_node);

    printf("\n");
    insert_tree_node(tree_node, 15);
    print_tree_node(tree_node);

    printf("\n");
    insert_tree_node(tree_node, 16);
    print_tree_node(tree_node);

    printf("\n");
    insert_tree_node(tree_node, 17);
    print_tree_node(tree_node);

    printf("\n");
    insert_tree_node(tree_node, 18);
    print_tree_node(tree_node);


    free_tree_node(tree_node);
    return 0;
}
