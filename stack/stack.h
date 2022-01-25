#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

#define STACK_ALLOCATION_ERROR 1
#define STACK_REALLOCATION_ERROR 2
#define EMPTY_STACK_ERROR 3

typedef struct s_stack
{
    void (*init)(struct s_stack *this);
    void (*destroy)(struct s_stack *this);

    int (*push)(struct s_stack *this, int value);
    int (*pop)(struct s_stack *this);
    void (*clear)(struct s_stack *this);

    bool (*is_full)(struct s_stack *this);
    bool (*is_empty)(struct s_stack *this);

    void (*display)(struct s_stack *this);

    unsigned int top;
    unsigned int capacity;
    bool error;
    int *values;
} Stack;

Stack *newStack();

#endif
