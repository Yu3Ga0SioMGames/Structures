#include "trees.h"

thread_local int container_error = 0;

Node *create_tree(int64_t input_data)
{
    Node *tree = (Node *)malloc(sizeof(Node));
    if(tree == NULL) {
        return NULL;
    }

    tree->data = input_data;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

void free_tree(Node *tree)
{

    free(tree->data);
    free(tree);
}
