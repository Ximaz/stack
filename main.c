#include <stdio.h>
#include <stdlib.h>
#include "include/stack.h"

int main()
{
    Stack *stack = new_stack();

    if (!stack)
    {
        perror("Error: Stack allocation.\n");
        return STACK_ALLOCATION_ERROR;
    }
    for (unsigned int i = 0; i < 10; i++)
    {
        if (stack->push(stack, i) == STACK_REALLOCATION_ERROR && stack->error)
        {
            perror("Error: Stack reallocation.\n");
            return STACK_REALLOCATION_ERROR;
        }
    }
    if (stack->push(stack, 10) == STACK_REALLOCATION_ERROR && stack->error)
    {
        perror("Error: Stack reallocation.\n");
        return STACK_REALLOCATION_ERROR;
    }
    stack->display(stack);
    stack->clear(stack);
    stack->display(stack);
    stack->destroy(stack);
    return 0;
}
