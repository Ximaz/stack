#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

struct Stack *StackInit(const int capacity)
{
    struct Stack *stack = malloc(sizeof(struct Stack));
    if (stack != NULL)
    {
        stack->capacity = capacity;
        stack->top = 0;
        stack->values = malloc(stack->capacity * sizeof(int *));
    }
    return stack;
}

void StackPush(struct Stack *stack, const int e)
{
    if (!StackIsFull(stack))
        stack->values[stack->top++] = e;
    else
        printf("[ERROR] : Stack is full !\n");
}

int StackPop(struct Stack *stack)
{
    if (!StackIsEmpty(stack))
        return stack->values[stack->top--];

    printf("[ERROR] : Stack is empty !\n");
    return -1;
}

void StackDisplay(struct Stack *stack)
{
    if (StackIsEmpty(stack))
        return;

    for (int i = 0; i < stack->top; i++)
        printf("|%d", stack->values[i]);

    printf("|\n");
}

void StackClear(struct Stack *stack)
{
    stack->top = -1;
}

void StackDestroy(struct Stack *stack)
{
    free(stack->values);
    free(stack);
}

int StackIsEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

int StackIsFull(struct Stack *stack)
{
    return stack->top == stack->capacity;
}
