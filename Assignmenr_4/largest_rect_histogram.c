/*
 * Problem-4: Largest Rectangle in Histogram
 * Raghav Munjal 1910990074 10/08/21
 * Assignment_4 -> Stack and Queue
*/

    int top=0;
    int stack[10000];
    bool isEmpty()
    {
        if(top<0)
            return true;
        else
            return false;
    }
    int peek()
    {
        return stack[top];
    }
    void pop()
    {
        top--;
    }
int largestRectangleArea(int* heights, int n){
    
    int ps[n],ns[n];
    ps[0] = -1;
    stack[top] = 0;
    for(int i=1;i<n;i++)
    {
        while(!isEmpty() && heights[peek()]>=heights[i])
        {
            pop();
        }
        ps[i] = isEmpty() ? -1 : peek();
        top++;
        stack[top]=i;
    }
    top=0;
    stack[top] = n-1;
    ns[n-1] = n;
    for(int i=n-2;i>=0;i--)
    {
        while(!isEmpty() && heights[peek()]>=heights[i])
        {
            pop();
        }
        ns[i] = isEmpty() ? n : peek();
        top++;
        stack[top]=i;
    }
    int result=0;
    for(int i=0;i<n;i++)
    {
        if((ns[i]-ps[i]-1)*heights[i]>result)
            result=(ns[i]-ps[i]-1)*heights[i];
    }
    top=0;
    return result;
}