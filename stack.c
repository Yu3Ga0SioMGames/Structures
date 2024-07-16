#include "stack.h"

bool expand_allocated_memory(Stack *stack)
{
    size_t new_size = stack->allocated * 2;
    int64_t *new_memory = (int64_t *)malloc(sizeof(int64_t) * new_size);
    if(new_memory == NULL) {
        stack->error = BAD_ALLOC_ERROR;
        return false;
    }

    for(int64_t i = 0; i < stack->stack_size; ++i) {
        new_memory[i] = stack->stack_data[i];
    }

    free(stack->stack_data);

    stack->stack_data = new_memory;
    stack->allocated = new_size;

    return true;
}

Stack *create_stack()
{
    Stack *new_stack = (Stack *)malloc(sizeof(Stack));
    if(new_stack == NULL) {
        return NULL;
    }

    new_stack->stack_data = malloc(sizeof(int64_t));
    if(new_stack->stack_data == NULL) {
        free(new_stack);
        return NULL;
    }
    new_stack->allocated = 1;
    new_stack->stack_size = 0;
    new_stack->error = 0;

    return new_stack;
}

void free_stack(Stack *stack)
{
    if(stack == NULL) {
        stack->error = ARRAY_NOT_PROVIDED;
        return;
    }

    free(stack->stack_data);
    free(stack);
}

void print_stack(Stack *stack)
{
    if(stack->stack_size == 0) {
        stack->error = STACK_IS_EMPTY;
        return;
    }

    for(size_t i = 0; i < stack->stack_size; ++i) {
        printf("%ld ", stack->stack_data[i]);
    }
    printf("\n");
}

void stack_push(Stack *stack, int64_t value)
{
    if(stack->stack_size == stack->allocated) {
        if(!expand_allocated_memory(stack)) {
            return;
        }

        expand_allocated_memory(stack);
    }

    stack->stack_data[stack->stack_size] = value;
    stack->stack_size++;
}


int64_t stack_pop(Stack *stack)
{
    if(stack->stack_size == 0) {
        return stack->error = STACK_IS_EMPTY;
    }

    return stack->stack_data[--stack->stack_size];
}

int64_t stack_peek(Stack *stack)
{
    if(stack->stack_size == 0) {
        return stack->error = STACK_IS_EMPTY;
    }

    return stack->stack_data[stack->stack_size - 1];
}
