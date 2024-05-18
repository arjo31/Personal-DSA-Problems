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
    for (int i =0; i<n; i++)
    {
        scanf("%d", arr+i);
    }
    int j;
    for (int i=0; i<n-1; i++)
    {
        j=i+1;
        if (arr[i]<=arr[i+1])
        {
            continue;
        }
        else{
            while (arr[j]<arr[j-1] && j>0)
            {
                swap(&arr[j-1],&arr[j]);
                j--;
            }
        }
    }
    for (int i=0; i<n; i++)
    {
        printf("%d ", *(arr+i));
    }
    return 0;
}