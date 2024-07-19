#include "stack_test.h"

int stack_test()
{
    Stack *stack;
    stack = NULL;

    printf("%ld\n", stack_pop(stack));
    printf("\n%ld\n\n", stack_peek(stack));

    stack = create_stack();
    int64_t initial_size = 10;


    stack_push(stack, 1);
    printf("%ld\n", stack_peek(stack));
    printf("\n%ld\n", stack_pop(stack));
    printf("\n%ld\n\n", stack_peek(stack));
    for(int64_t i = 0; i < initial_size; ++i) {
        stack_push(stack, i);
    }
    stack_push(stack, 87);
    print_stack(stack);
    printf("\n%ld\n\n", stack_pop(stack));
    print_stack(stack);
    printf("\n%ld\n\n", stack_peek(stack));

    free_stack(stack);
    return 0;
}
