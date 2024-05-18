#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i =0; i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<n-1; i++)
    {
        int count=0;
        for (int j=0; j<n-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                count++;
            }
        }
        if (count==0)
        {
            break;
        }    
    }
    for (int i=0; i<n ;i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}