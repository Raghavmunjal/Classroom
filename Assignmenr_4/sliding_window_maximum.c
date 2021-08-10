/*
 * Problem-6: Sliding Window
 * Raghav Munjal 1910990074 10/08/21
 * Assignment_4 -> Stack and Queue
*/

typedef struct {
    int front;
    int rear;
    int *arr;
    int  capacity;
} Dequeue;

Dequeue *createDequeue(){
    Dequeue *obj = (Dequeue *)malloc(sizeof(Dequeue));
    obj->front = 0;
    obj->rear = -1;
    obj->capacity = 100000;
    obj->arr = (int*)calloc(obj->capacity, sizeof(int));

    return obj;
}
int isEmpty(Dequeue *dq){
    if(dq->rear == -1)
        return 1;
    return 0;
}

void addFirst(Dequeue *dq, int val){
    if(dq->front == 0){
        dq->front = dq->capacity-1;
    }else{
        dq->front--;
    }
    dq->arr[dq->front] = val;
}

void addLast(Dequeue *dq, int val){
    if(dq->rear == dq->capacity-1){
        dq->rear = 0;
    }else{
        dq->rear++;
    }
    dq->arr[dq->rear] = val;
}

void removeFirst(Dequeue *dq){
    if(dq->front == dq->rear){
        dq->front = 0;
        dq->rear = -1;
    }else if(dq->front == dq->capacity-1){
        dq->front = 0;
    }else{
        dq->front++;
    }
}

void removeLast(Dequeue *dq){
    if(dq->rear == dq->front){
        dq->front = 0;
        dq->rear = -1;
    }else if(dq->rear == 0){
        dq->rear = dq->capacity-1;
    }else{
        dq->rear--;
    }
}

int peekFirst(Dequeue *dq){
    return dq->arr[dq->front];
}

int peekLast(Dequeue *dq){
    return dq->arr[dq->rear];
}


int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    *returnSize = numsSize-k+1;
    int *arr = (int*)calloc(*returnSize, sizeof(int));
        Dequeue *dq= createDequeue();
        for(int i=0;i<k;i++){
            while(!isEmpty(dq) && nums[peekLast(dq)]<=nums[i]){
                removeLast(dq);
            }
            addLast(dq, i);
        }
        int n=0;
        for(int i=k;i<numsSize;i++){
            arr[n]=nums[peekFirst(dq)];
            while(!isEmpty(dq) && peekFirst(dq)<=i-k){
                removeFirst(dq);
            }
             while(!isEmpty(dq) && nums[peekLast(dq)]<=nums[i]){
                removeLast(dq);
            }
            addLast(dq, i);
            n++;
        }
        arr[n]=nums[peekFirst(dq)];
        return arr;

}