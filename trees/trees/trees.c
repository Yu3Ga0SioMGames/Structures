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
    if(tree == NULL) {
        container_error = TREE_NOT_PROVIDED;
        return;
    }

    free(tree->data);
    free(tree);
}

void print_stack(Stack *stack)
{
    if(stack == NULL) {
        container_error = STACK_NOT_PROVIDED;
        return;
    }

    if(stack->stack_size == 0) {
        container_error = STACK_IS_EMPTY;
        return;
    }

    for(size_t i = 0; i < stack->stack_size; ++i) {
        printf("%ld ", stack->stack_data[i]);
    }
    printf("\n");
}
