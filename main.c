#include <stdio.h>
#include <stdlib.h>

#include "stack/stack.h"

int main()
{
    // Creating a new empty stack :
    Stack *stack = newStack();

    if (stack == NULL)
        goto stackAllocationError;

    // Fill the stack with numbers :
    for (unsigned int i = 0; i < 10; i++)
    {
        if (stack->push(stack, i) == STACK_REALLOCATION_ERROR && stack->error)
            goto stackReallocationError;
    }

    // A simple test to check that the upgrade feature works :
    if (stack->push(stack, 10) == STACK_REALLOCATION_ERROR && stack->error)
        goto stackReallocationError;

    // Display the full-filled stack :
    stack->display(stack);

    // Clear the stack :
    stack->clear(stack);

    // Display again the empty stack :
    stack->display(stack);

    // Destroy the stack using free :
    stack->destroy(stack);
    return 0;

stackAllocationError:
    printf("Error: Stack allocation.\n");
    return STACK_ALLOCATION_ERROR;

stackReallocationError:
    printf("Error: Stack reallocation.\n");
    return STACK_REALLOCATION_ERROR;
}
