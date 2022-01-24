typedef struct Stack
{
    int cursor;
    int size;
    int *values;
} Stack;

struct Stack *StackInit(const int size);
void StackPush(struct Stack *stack, const int e);
int StackIsFull(struct Stack *stack);
int StackPop(struct Stack *stack);
int StackIsEmpty(struct Stack *stack);
void StackClear(struct Stack *stack);
void StackDestroy(struct Stack *stack);
void StackDisplay(struct Stack *stack);