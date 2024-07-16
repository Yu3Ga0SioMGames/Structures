#include "stack.h"

int main()
{
    int64_t initial_size = 10;

    Stack *stack;
    stack = create_stack();

    /// [First] Check the Stack, if it is empty, then output = 3(Check screnshots)...
    printf("%ld\n", stack_peek(stack));
    printf("\n%ld\n\n", stack_pop(stack));

    stack_push(stack, 1); // Add new element(1)...

    /// [Second] Check it(New element) and delete it...
    printf("%ld\n", stack_peek(stack));
    printf("\n%ld\n", stack_pop(stack));

    /// [Third] Check the Stack(Again, "It" must be empty(3))...
    printf("\n%ld\n\n", stack_peek(stack));

    /// [Fourth] Other, default operation...
    for(int64_t i = 0; i < initial_size; ++i) {
        stack_push(stack, i);
    }
    stack_push(stack, 87);
    print_stack(stack);
    printf("\n%ld\n\n", stack_pop(stack));
    print_stack(stack);
    printf("\n%ld\n\n", stack_peek(stack));

    /// End of programm...
    free_stack(stack);
    return 0;
}
