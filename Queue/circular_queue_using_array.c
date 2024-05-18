#include <stdio.h>
#include <stdlib.h>

int front=-1;
int rear=-1;

#define size 100

int arr[size];

void enqueue(int data)
{
    if (rear==size-1||front==(rear+1)%size)
    {
        printf("Queue is full");
        exit(0);
    }
    else
    {
        if (front==-1)
        {
            front++;
        }
        rear=(rear+1)%size;
        arr[rear]=data;
    }
}

void dequeue()
{
    int element;
    if (front==-1)
    {
        printf("Deletion not possible\n ");
        exit(0);
    }
    else
    {
        element=arr[front];
        if (front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front=(front+1)%size;
        }
    }
    printf("Deleted element = %d\n", element);
}

void display()
{
    if (front==-1)
    {
        printf("Queue is empty");
        exit(0);
    }
    else
    {
        for(int i=front;i<=rear;i=(i+1)%size)
        {
            printf("Element = %d\n", arr[i]);
        }
    }
}

int main()
{
    while (1)
    {
        printf("Enter choice : \n1. Insert in queue\n2. Delete from queue\n3. Display the queue\n4. Exit\n");                
        int choice;
        scanf("%d", &choice);
        if (choice==1)
        {
            int data; 
            printf("Enter the value to be inserted = ");
            scanf("%d", &data);
            enqueue(data);
        }        
        else if(choice==2)
        {
            dequeue();
        }
        else if(choice==3)
        {
            display();
        }
        else if (choice==4)
        {
            exit(0);
        }
        else
        {
            printf("Invalid choice");
        }

    }
    return 0;
}
