232. Implement Queue using Stacks
typedef struct {
    int *inStack;
    int *outStack;
    int topIn;
    int topOut;
    int size;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->size = 100;  // max size
    obj->inStack = (int*)malloc(sizeof(int) * obj->size);
    obj->outStack = (int*)malloc(sizeof(int) * obj->size);
    obj->topIn = -1;
    obj->topOut = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->inStack[++obj->topIn] = x;
}

void transfer(MyQueue* obj) {
    while (obj->topIn != -1) {
        obj->outStack[++obj->topOut] = obj->inStack[obj->topIn--];
    }
}

int myQueuePop(MyQueue* obj) {
    if (obj->topOut == -1) {
        transfer(obj);
    }
    return obj->outStack[obj->topOut--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->topOut == -1) {
        transfer(obj);
    }
    return obj->outStack[obj->topOut];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->topIn == -1 && obj->topOut == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj->inStack);
    free(obj->outStack);
    free(obj);
}
