#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

struct Stack *StackInit(const int size)
{
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->size = size;
    stack->cursor = -1;
    stack->values = malloc(stack->size * sizeof(int *));
    return stack;
}

void StackPush(struct Stack *stack, const int e)
{
    stack->values[++stack->cursor] = e;
}

int StackPop(struct Stack *stack)
{
    return stack->values[--stack->cursor];
}

void StackDisplay(struct Stack *stack)
{
    int *array = stack->values;
    int *start = &array[0];         // Points to the first array's element.
    int *end = &array[stack->size]; // Points to the last array's element.

    // Points to NULL and then, to each array elements.
    for (int *ptr = start; ptr < end; ptr++)
    {
        const int i = ptr - start;
        const int e = array[i];
        printf("|%d", e);
    }
    printf("|\n");
}

void StackClear(struct Stack *stack)
{
    stack->cursor = -1;
    free(stack->values);
    stack->values = malloc(stack->size * sizeof(int));
}

void StackDestroy(struct Stack *stack) {
    free(stack->values);
    free(stack);
}

int StackIsEmpty(struct Stack *stack)
{
    return stack->cursor == -1;
}

int StackIsFull(struct Stack *stack)
{
    return stack->cursor == stack->size - 1;
}