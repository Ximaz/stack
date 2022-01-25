#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *StackInit(int capacity, bool upgradable)
{
    Stack *this = malloc(sizeof(Stack));
    if (this != NULL)
    {
        this->top = 0;
        this->capacity = capacity;
        this->upgradable = upgradable;
        this->values = malloc(this->capacity * sizeof(int *));
    }
    else
        printf("[ERROR] : Unabled to allocate memory to initialize the this !\n");
    return this;
}

void StackDestroy(Stack *this)
{
    free(this->values);
    free(this);
}

void StackPush(Stack *this, int value)
{
    if (this->upgradable && StackIsFull(this))
    {
        this->values = realloc(this->values, (this->capacity += sizeof(int)) * sizeof(int));
        if (this->values == NULL)
        {
            printf("[ERROR] : Unabled to reallocate memory for the this values !\n");
            return;
        }
    }

    if (!StackIsFull(this))
        this->values[this->top++] = value;
    else
        printf("[ERROR] : Stack is full !\n");
}

bool StackIsFull(Stack *this)
{
    return this->top == this->capacity;
}

int StackPop(Stack *this)
{
    if (!StackIsEmpty(this))
        return this->values[this->top--];

    printf("[ERROR] : Stack is empty !\n");
    return -1;
}

bool StackIsEmpty(Stack *this)
{
    return this->top == -1;
}

void StackClear(Stack *this)
{
    this->top = -1;
}

void StackDisplay(Stack *this)
{
    if (StackIsEmpty(this))
        return;

    for (int i = 0; i < this->top; i++)
        printf("|%d", this->values[i]);

    printf("|\n");
}
