#include "stack.h"

int main()
{
    int64_t initial_size = 10;

    Stack *stack;
    stack = create_stack();

    for(int64_t i = 0; i < initial_size; ++i) {
        stack_push(stack, i);
    }

    stack_push(stack, 87); // Добавляет элемент с заданным значением(Вызывался ещё выше в "11" строчке);

    print_stack(stack); // Выводит сам стёк на экран;

    printf("\n%ld\n\n", stack_pop(stack)); // Вывод на экран верхушку стёка(Удалённый элемент);

    print_stack(stack); // Выводит сам стёк на экран(Вызывался ещё выше в "16" строчке);

    printf("\n%ld\n\n", stack_peek(stack)); // Выводит на экран верхушку стёка;

    free_stack(stack);
    return 0;
}
