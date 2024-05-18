#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link;
};

struct node*front=NULL;
struct node*rear=NULL;

void enqueue(int data)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->link=NULL;
    n->data=data;
    if (n==NULL)
    {
        printf("Element can't be inserted");
        exit(0);
    }
    else
    {
        if (front==NULL)
        {
            front=n;
            rear=n;
            rear->link=front;
        }
        else{        
        rear->link=n;
        rear=n;
        n->link=front;
        }
    }    
}

void dequeue()
{
    struct node* p;
    p=front;
    if (front==NULL)
    {
        printf("Deletion not possible");
        exit(0);
    }
    else if (front==rear)
    {
        front=NULL;
        rear=NULL;
        free(p);
    }
    else
    {
        printf("Deleted element = %d\n",p->data);
        front=front->link;
        rear->link=front;
        free(p);
    }
}

void display()
{
    struct node *p;
    p=front;
    if (front==NULL)
    {
        printf("Empty Queue");
        exit(0);
    }
    else
    {
        do
        {
            printf("Element = %d\n", p->data);
            p=p->link;
        } while (p!=front);        
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
            int ele; 
            printf("Enter the value to be inserted = ");
            scanf("%d", &ele);
            enqueue(ele);
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