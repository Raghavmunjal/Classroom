/*
 * Problem-3: Implement Stack Using queue
 * Raghav Munjal 1910990074 10/08/21
 * Assignment_4 -> Stack and Queue
*/

typedef struct {
    int front;
    int rear;
    int *arr;
} Queue;

Queue* createQueue() {
    Queue *obj = (Queue*)malloc(sizeof(Queue));
    obj->arr = (int*)calloc(100, sizeof(int));
    obj->front = 0;
    obj->rear = -1;
    return obj;
}

void add(Queue *q, int x) {
    q->arr[++q->rear] = x;
}

int poll(Queue *q) {
    return q->arr[q->front++];
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}
int top(Queue *q){
    return q->arr[q->front];
}


typedef struct {
    Queue *q1;
    Queue *q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *obj = (MyStack*)malloc(sizeof(MyStack));
    obj->q1 = createQueue();
    obj->q2 = createQueue();

    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    add(obj->q2, x);
    int res;
    while(!isEmpty(obj->q1)) {
        res = poll(obj->q1);
        add(obj->q2, res);
    }
    Queue *temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if(isEmpty(obj->q1)){
        return -1;
    }else{
        return poll(obj->q1);
    }
}


/** Get the top element. */
int myStackTop(MyStack* obj) {
    if(isEmpty(obj->q1)){
        return -1;
    }else{
        return top(obj->q1);
    }
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
  return isEmpty(obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj);
}