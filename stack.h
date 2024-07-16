#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define BAD_ALLOC_ERROR 1
#define ARRAY_NOT_PROVIDED (BAD_ALLOC_ERROR + 1)
#define STACK_IS_EMPTY (ARRAY_NOT_PROVIDED + 1)

typedef
struct _stack
{
    int error;
    int64_t *stack_data;
    size_t allocated;
    size_t stack_size;
} Stack;

Stack *create_stack();

void free_stack(Stack *);

void print_stack(Stack *);

void stack_push(Stack *, int64_t);

int64_t stack_peek(Stack *);

int64_t stack_pop(Stack *);

#endif
