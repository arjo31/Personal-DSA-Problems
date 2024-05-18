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
    for (int i=0; i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    int min_idx;
    for (int i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (int j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }


    return 0;
}