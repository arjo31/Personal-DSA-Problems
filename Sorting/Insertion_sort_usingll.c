// C program to sort link list
// using insertion sort
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* link;
};

void display(struct node* s)
{
	while (s!=NULL)
	{
		printf("Element = %d\n", s->data);
		s=s->link;
	}
}

void sort(struct node* s)
{
	struct node *ptr,*cpt;
	ptr=s;
	while (ptr->link!=NULL)
	{
		cpt=ptr->link;
		while (cpt!=NULL)
		{  
			if (ptr->data > cpt->data)
			{
				int temp = ptr->data;
				ptr->data = cpt->data;
				cpt->data=temp;
			}
			cpt=cpt->link;
		}
		ptr=ptr->link;
	}
}


int main()
{

	int n;
    scanf("%d", &n);
    struct node* p,*prev,*head;
	head=NULL;
    for (int i=0;i<n;i++)
    {
        p=malloc(sizeof(struct node));
        scanf("%d", &p->data);
        p->link=NULL;
        if (head==NULL)
        {
            head=p;
        }
        else
        {
            prev->link=p;
        }
        prev=p;

    }

	printf("Linked List before sorting:\n");
	display(head);
	printf("\n");
    
	sort(head);

	printf("Linked List after sorting:\n");
	display(head);
	printf("\n");

	return 0;
}	
