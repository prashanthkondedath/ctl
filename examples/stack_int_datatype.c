#include <stdio.h>
#include "../include/ctl.h"

CTL_DEFINE_STACK_TYPE(int, int)
CTL_DEFINE_STACK_FUNCTIONS(int, int)

int main() {
    Stack_int* stack = Stack_int_create();

    Stack_int_push(stack, 10);
    Stack_int_push(stack, 20);
    Stack_int_push(stack, 30);

    printf("Popped Item: %d\n", Stack_int_pop(stack));
    printf("Popped Item: %d\n", Stack_int_pop(stack));
    printf("Popped Item: %d\n", Stack_int_pop(stack));

    Stack_int_destroy(stack);

    return 0;
}
