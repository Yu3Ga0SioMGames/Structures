#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <threads.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define BAD_ALLOC_ERROR 1
#define STACK_NOT_PROVIDED (BAD_ALLOC_ERROR + 1)
#define STACK_IS_EMPTY (STACK_NOT_PROVIDED + 1)

extern thread_local int container_error;

typedef
struct _stack
{
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
