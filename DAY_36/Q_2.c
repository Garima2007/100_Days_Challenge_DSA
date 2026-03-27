641. Design Circular Deque

typedef struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct 
{
    Node* head;     
    Node* tail;     
    int size;
    int capacity;
} MyCircularDeque;
Node* createNode(int val)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->prev = NULL;
    node->next = NULL;
    return node;
}
MyCircularDeque* myCircularDequeCreate(int k) 
{
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->head = createNode(0);
    obj->tail = createNode(0);
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;
    obj->size = 0;
    obj->capacity = k;
    return obj;
}
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) 
{
    if (obj->size == obj->capacity) return false;
    Node* node = createNode(value);
    node->next = obj->head->next;
    node->prev = obj->head;
    obj->head->next->prev = node;
    obj->head->next = node;
    obj->size++;
    return true;
}
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) 
{
    if (obj->size == obj->capacity) return false;
    Node* node = createNode(value);
    node->prev = obj->tail->prev;
    node->next = obj->tail;
    obj->tail->prev->next = node;
    obj->tail->prev = node;
    obj->size++;
    return true;
}
bool myCircularDequeDeleteFront(MyCircularDeque* obj) 
{
    if (obj->size == 0) return false;
    Node* node = obj->head->next;
    obj->head->next = node->next;
    node->next->prev = obj->head;
    free(node);
    obj->size--;
    return true;
}
bool myCircularDequeDeleteLast(MyCircularDeque* obj) 
{
    if (obj->size == 0) return false;
    Node* node = obj->tail->prev;
    obj->tail->prev = node->prev;
    node->prev->next = obj->tail;
    free(node);
    obj->size--;
    return true;
}
int myCircularDequeGetFront(MyCircularDeque* obj) 
{
    if (obj->size == 0) return -1;
    return obj->head->next->val;
}
int myCircularDequeGetRear(MyCircularDeque* obj) 
{
    if (obj->size == 0) return -1;
    return obj->tail->prev->val;
}
bool myCircularDequeIsEmpty(MyCircularDeque* obj) 
{
    return obj->size == 0;
}
bool myCircularDequeIsFull(MyCircularDeque* obj) 
{
    return obj->size == obj->capacity;
}
void myCircularDequeFree(MyCircularDeque* obj) 
{
    Node* curr = obj->head;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(obj);
}
