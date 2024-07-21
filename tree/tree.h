#ifndef TREES_H_INCLUDED
#define TREES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#include "common.h"

typedef
struct _tree_node
{
    int64_t data;
    struct _tree_node *left;
    struct _tree_node *right;
} TreeNode;

TreeNode *create_tree(int64_t);

void free_tree_node(TreeNode *);

void print_tree_node(TreeNode *);

#endif
