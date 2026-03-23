Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
#include <stdlib.h>

typedef struct {
    int *stack;
    int *minStack;
    int top;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->stack = (int*)malloc(10000 * sizeof(int));
    obj->minStack = (int*)malloc(10000 * sizeof(int));
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;

    if (obj->top == 0) {
        obj->minStack[obj->top] = val;
    } else {
        if (val < obj->minStack[obj->top - 1])
            obj->minStack[obj->top] = val;
        else
            obj->minStack[obj->top] = obj->minStack[obj->top - 1];
    }
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->minStack);
    free(obj);
}
