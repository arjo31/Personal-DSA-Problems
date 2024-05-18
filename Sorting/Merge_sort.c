#include <stdio.h>

void merge(int arr[],int l[],int r[],int left,int right)
{
    int i=0,j=0,k=0;
    while (i<left && j<right)
    {
        if (l[i]<r[j])
        {
            arr[k]=l[i];
            i++;
        }
        else
        {
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    while (i<left)
    {
        arr[k]=l[i];
        i++;
        k++;
    }
    while(j<right)
    {
        arr[k]=r[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int size)
{
    int n=size;
    if(n>=2)
    {
        int mid=n/2;
        int left[mid];
        int right[n-mid];
        for (int i=0;i<mid;i++)
        {
            left[i]=arr[i];
        }
        for (int i=mid;i<n;i++)
        {
            right[i-mid]=arr[i];
        }
        mergesort(left,mid);
        mergesort(right,n-mid);
        merge(arr,left,right,mid,n-mid);
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
    mergesort(arr,n);
    printf("Array after sorting : ");
    display(arr,0,n-1);
    return 0;
}