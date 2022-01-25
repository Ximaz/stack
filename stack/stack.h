#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

typedef struct s_stack
{
    int top;
    int capacity;
    bool upgradable;
    int *values;
} Stack;

Stack *StackInit(int size, bool upgradable);
void StackDestroy(Stack *this);
void StackPush(Stack *this, int value);
bool StackIsFull(Stack *this);
int StackPop(Stack *this);
bool StackIsEmpty(Stack *this);
void StackClear(Stack *this);
void StackDisplay(Stack *this);

#endif
