#include "stack.h"

thread_local int container_error = 0;

bool expand_allocated_memory(Stack *stack)
{
    if(stack == NULL) {
        container_error = STACK_NOT_PROVIDED;
        return false;
    }

    size_t new_size = stack->allocated * 2;
    int64_t *new_memory = (int64_t *)malloc(sizeof(int64_t) * new_size);
    if(new_memory == NULL) {
        container_error = BAD_ALLOC_ERROR;
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
        container_error = BAD_ALLOC_ERROR;
        return NULL;
    }

    new_stack->stack_data = malloc(sizeof(int64_t));
    if(new_stack->stack_data == NULL) {
        container_error = BAD_ALLOC_ERROR;
        free(new_stack);
        return NULL;
    }
    new_stack->allocated = 1;
    new_stack->stack_size = 0;

    return new_stack;
}

void free_stack(Stack *stack)
{
    if(stack == NULL) {
        container_error = STACK_NOT_PROVIDED;
        return;
    }

    free(stack->stack_data);
    free(stack);
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

void stack_push(Stack *stack, int64_t value)
{
    if(stack == NULL) {
        container_error = STACK_NOT_PROVIDED;
        return;
    }

    if(stack->stack_size == stack->allocated) {
        if(!expand_allocated_memory(stack)) {
            container_error = BAD_ALLOC_ERROR;
            return;
        }
    }

    stack->stack_data[stack->stack_size] = value;
    stack->stack_size++;
}


int64_t stack_pop(Stack *stack)
{
    if(stack == NULL) {
        return container_error = STACK_NOT_PROVIDED;
    }

    if(stack->stack_size == 0) {
        return container_error = STACK_IS_EMPTY;
    }

    return stack->stack_data[--stack->stack_size];
}

int64_t stack_peek(Stack *stack)
{
    if(stack == NULL) {
        return container_error = STACK_NOT_PROVIDED;
    }

    if(stack->stack_size == 0) {
        return container_error = STACK_IS_EMPTY;
    }

    return stack->stack_data[stack->stack_size - 1];
}
