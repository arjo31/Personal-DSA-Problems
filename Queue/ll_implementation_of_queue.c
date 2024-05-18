#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node*front=NULL;
struct node*rear=NULL;

void enqueue(int data)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    if (p==NULL)
    {
        printf("Overflow");
        exit(0);
    }
    else
    {
        p->data=data;
        if(front==NULL)
        {
            front=p;
            rear=p;
            front->link=NULL;
            rear->link=NULL;
        }
        rear->link=p;
        rear=p;
        rear->link=NULL;
    }
}

void dequeue()
{
    struct node *p;
    if (front==NULL)
    {
        printf("Element can't be deleted ");
        exit(0);
    }
    else
    {
        p=front;
        printf("Element = %d\n", p->data);
        front=front->link;
        free(p);
    }
}

void display()
{
    struct node*p;
    p=front;
    if (p==NULL)
    {
        printf("Empty Queue");
        exit(0);
    }
    else
    {
        while(p!=NULL)
        {
            printf("Element = %d\n", p->data);
            p=p->link;
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