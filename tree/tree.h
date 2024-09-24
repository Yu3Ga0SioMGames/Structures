#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#include "common.h"

typedef
struct _tree_node
{
	int64_t data;
	int8_t balance_factor;
	struct _tree_node *left;
	struct _tree_node *right;
} TreeNode;

TreeNode *create_tree_node(int64_t);

void free_tree_node(TreeNode *);

void free_this_tree_node(TreeNode *);

void print_tree_node(TreeNode *);

void insert_tree_node(TreeNode **, TreeNode *);

void insert_tree_value(TreeNode **, int64_t);

TreeNode *find_tree_node(TreeNode *, int64_t);

void remove_tree_node(TreeNode **, int64_t);

TreeNode *rotate_left_tree_node(TreeNode *);

TreeNode *rotate_right_tree_node(TreeNode *);

//void balance_tree_node(TreeNode **);

#endif
