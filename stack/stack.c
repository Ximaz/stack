#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack *StackInit(const int capacity, const _Bool upgradable)
{
    struct Stack *stack = malloc(sizeof(struct Stack));
    if (stack != NULL)
    {
        stack->top = 0;
        stack->capacity = capacity;
        stack->upgradable = upgradable;
        stack->values = malloc(stack->capacity * sizeof(int *));
    }
    else
        printf("[ERROR] : Unabled to allocate memory to initialize the stack !\n");
    return stack;
}

void StackPush(struct Stack *stack, const int e)
{
    if (stack->upgradable && StackIsFull(stack))
    {
        stack->values = realloc(stack->values, ++stack->capacity * sizeof(int *));
        if (stack->values == NULL)
        {
            printf("[ERROR] : Unabled to reallocate memory for the stack values !\n");
            return;
        }
    }

    if (!StackIsFull(stack))
        stack->values[stack->top++] = e;
    else
        printf("[ERROR] : Stack is full !\n");
}

int StackIsFull(struct Stack *stack)
{
    return stack->top == stack->capacity;
}

int StackPop(struct Stack *stack)
{
    if (!StackIsEmpty(stack))
        return stack->values[stack->top--];

    printf("[ERROR] : Stack is empty !\n");
    return -1;
}

int StackIsEmpty(struct Stack *stack)
{
    return stack->top == -1;
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

void StackDisplay(struct Stack *stack)
{
    if (StackIsEmpty(stack))
        return;

    for (int i = 0; i < stack->top; i++)
        printf("|%d", stack->values[i]);

    printf("|\n");
}
