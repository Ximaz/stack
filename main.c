#include <stdio.h>
#include <stdlib.h>

#include "stack/stack.h"

#define STACK_SIZE 10
#define STACK_UPGADABLE 1 // Or 1.

int main(const int argc, const char **argv)
{
    // Creating a new stack which can contain STACK_SIZE element :
    struct Stack *stack = StackInit(STACK_SIZE, STACK_UPGADABLE);

    // Fill the stack with numbers :
    for (int i = 0; i < stack->capacity; i++)
        StackPush(stack, i);

    // A simple test to check that the upgrade feature works :
    StackPush(stack, 10);

    // Display the full-filled stack :
    StackDisplay(stack);

    // Clear the stack :
    StackClear(stack);

    // Display again the empty stack :
    StackDisplay(stack);

    // Destroy the stack using free :
    StackDestroy(stack);
    return 0;
}
