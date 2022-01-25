#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void stack_init(Stack *this)
{
    if (this != NULL)
    {
        this->top = 0;
        this->capacity = 1;
        this->error = false;
        this->values = malloc(sizeof(int));
    }
}

void stack_destroy(Stack *this)
{
    free(this->values);
    free(this);
}

int stack_push(Stack *this, int value)
{
    if (this->is_full(this))
    {
        this->capacity++;
        this->values = realloc(this->values, this->capacity * sizeof(int));
        if (this->values == NULL)
        {
            if (!this->error)
                this->error = true;
            return STACK_REALLOCATION_ERROR;
        }
    }
    if (this->error)
        this->error = false;
    this->values[this->top++] = value;
    return 0;
}

bool stack_is_full(Stack *this)
{
    return this->top == this->capacity;
}

int stack_pop(Stack *this)
{
    if (!this->is_empty(this))
    {
        if (this->error)
            this->error = false;
        return this->values[this->top--];
    }

    if (!this->error)
        this->error = true;
    return EMPTY_STACK_ERROR;
}

bool stack_is_empty(Stack *this)
{
    return this->top == 0;
}

void stack_clear(Stack *this)
{
    this->top = 0;
}

void stack_display(Stack *this)
{
    if (this->is_empty(this))
        return;

    for (unsigned int i = 0; i < this->top; i++)
        printf("|%d", this->values[i]);

    printf("|\n");
}

Stack *newStack()
{
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL)
        return NULL;

    stack->init = &stack_init;
    stack->destroy = &stack_destroy;
    stack->push = &stack_push;
    stack->pop = &stack_pop;
    stack->is_empty = &stack_is_empty;
    stack->is_full = &stack_is_full;
    stack->clear = &stack_clear;
    stack->display = &stack_display;
    stack->init(stack);
    return stack;
}
