#include <stdio.h>

void swap(int *a,int*b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int index=low;
    for (int i=low;i<high;i++)
    {
        if(arr[i]<pivot)
        {
            swap(&arr[i],&arr[index]);
            index++;
        }
    }
    swap(&arr[high],&arr[index]);
    return index;
}

void qs(int arr[],int low,int high)
{
    int index;
    if (low<high)
    {
        index=partition(arr,low,high);
        qs(arr,low,index-1);
        qs(arr,index+1,high);
    }
}

void display(int arr[],int low, int high)
{
    for (int i=low;i<=high;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of the array = ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of array : \n");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Array before sorting : ");
    display(arr,0,n-1);
    qs(arr,0,n-1);
    printf("Array after sorting : ");
    display(arr,0,n-1);
    return 0;
}