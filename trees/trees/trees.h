#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdint.h>

#include "common.h"

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

}

#endif
