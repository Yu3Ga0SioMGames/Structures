#ifndef TREES_H_INCLUDED
#define TREES_H_INCLUDED

#include <stdint.h>

#define TREE_NOT_PROVIDED 1
// #define BAD_ALLOC_ERROR (TREE_NOT_PROVIDED + 1)
// #define TREE_IS_EMPTY (BAD_ALLOC_ERROR + 1)

extern thread_local int container_error;

typedef
struct _node
{
    int64_t data;
    struct _node *left;
    struct _node *right;
} Node;

Node *create_tree();

void free_tree();

void print_tree(Node *stack)
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

#endif
