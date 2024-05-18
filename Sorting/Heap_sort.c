#include <stdio.h>
#include <stdlib.h>

int size=0;

void swap(int *a,int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int arr[],int i,int size)
{
        int largest =i;
        int l=2*i+1;
        int r=2*i+2;
        if (l<=size-1 && arr[l]>arr[largest])
        {
            largest=l;
        }
        if(r<=size-1 && arr[r]>arr[largest])
        {
            largest=r;
        }
        if (largest!=i)
        {
            swap(&arr[i],&arr[largest]);
            heapify(arr,largest,size);
        }
    
}

void insert(int arr[],int data)
{
    if (size==0)
    {
        arr[size]=data;
        size++;
    }
    else
    {
        arr[size]=data;
        size++;
        for (int i=(size-1)/2;i>=0;i--)
        {
            heapify(arr,i,size);
        }
    }
}

void heapsort(int arr[],int size)
{
    for (int i=(size-1)/2;i>=0;i--)
    {
        heapify(arr,i,size);
    }
    for (int i=size-1;i>=0;i--)
    {
       swap(arr,arr+i);
       heapify(arr,0,i);
    }
}

void display(int arr[],int size)
{
    for (int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of nodes in heap = ");
    scanf("%d",&n);
    int arr[100];
    for (int i=0;i<n;i++)
    {
        int ele;
        scanf("%d",&ele);
        insert(arr,ele);
    }
    display(arr,n);
    heapsort(arr,n);
    printf("Sorted array is : \n");
    display(arr,n);
    return 0;
}