/*
 * Problem : Implement Stack using Linked List.
 * Raghav 1910990074 25/08/21
 * Assignment_6 -> Linked List
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* top;


void push(int data)
{
	
	struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));

	
	if (!temp)
	{
		printf("\nHeap Overflow");
	}


	temp->data = data;
	
	temp->next = top;
	
	top = temp;
}


int isEmpty()
{
	return top == NULL;
}


int peek()
{
	
	if (!isEmpty())
		return top->data;
	else
		return -1;
}


void pop()
{
	struct Node* temp;

	if (top == NULL)
	{
		printf("\nStack Underflow");
		
	}
	else
	{
		
		temp = top;

		top = top->next;

		temp->next = NULL;
		
		free(temp);
	}
}


void display()
{
	struct Node* temp;

	if (top == NULL)
	{
		printf("\nStack Underflow");
	}
	else
	{
		temp = top;
		while (temp != NULL)
		{

			printf("%d ",temp->data);

			temp = temp->next;
		}
	}
}


int main()
{
	
	push(11);
	push(22);
	push(33);
	push(44);

	display();

	printf("\nTop element is %d\n",peek()); 

	pop();
	pop();

	display();

    printf("\nTop element is %d\n",peek()); 
		
	return 0;
}


