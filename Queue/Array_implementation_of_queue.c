#include <stdio.h>
#include <stdlib.h>

#define size 100

int f=-1;
int r=-1;
int arr[size];

void enqueue(int data)
{
    if (r==size-1)
    {
        printf("Overflow");
        exit(0);
    }
    else
    {
        if (f==-1)
        {
            f++;
        }
        arr[++r]=data;
    }
}

void dequeue()
{
    if (f>r||f==-1)
    {
        printf("Element can't be deleted");
        exit(0);
    }
    else
    {
        printf("Deleted element is = %d\n", arr[f]);
        f++;
    }
}

void display()
{
    int i;
    if (f==-1)
    {
        printf("Empty Queue");
        exit(0) ;
    }else{
    for (i=f; i<=r; i++)
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