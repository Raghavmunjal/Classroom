/*
 * Problem-5: MinStack
 * Raghav Munjal 1910990074 10/08/21
 * Assignment_4 -> Stack and Queue
*/

typedef struct {
    int stack[8000];
    int top_index;
    int min[200];
    int min_count;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *Min;
    Min = (MinStack*)malloc(sizeof(MinStack));
    Min->top_index = -1;
    Min->min_count = -1;
    return Min;
}

void minStackPush(MinStack* obj, int x) {
    obj->top_index++;
    obj->stack[obj->top_index] = x;
    
    if( obj->min_count == -1 || x <= obj->min[obj->min_count] )
    {
        obj->min_count++;
        obj->min[obj->min_count] = x;
    }
}

void minStackPop(MinStack* obj) {
    if(obj->top_index == -1)
        return ;
    
    
    else if( obj->stack[obj->top_index] == obj->min[obj->min_count] )
        obj->min_count--;
    
    obj->top_index--;
}

int minStackTop(MinStack* obj) {

    return obj->stack[obj->top_index];
}

int minStackGetMin(MinStack* obj) {

    return obj->min[obj->min_count];
}

void minStackFree(MinStack* obj) {
    free(obj);
}