#include <stdio.h>
#include<stdlib.h>

void merge_sort(int *a, int n);
void merge(int *a, int start, int mid, int end);

int main()
{
    int length, *arr, i;
    printf("Enter the array length:");
    scanf("%d", &length);

    arr = (int *)malloc(length * sizeof(int));
    printf("Enter the array elements:\n");
    for (i = 0; i < length; ++i)
    {
        scanf("%d", arr + i);
    }

    merge_sort(arr, length);

    printf("The sorted array is :\n");
    for(i = 0; i < length; ++i)
    {
        printf("%d\n", *(arr + i));
    }

    return 0;
}

void merge_sort(int *a, int n)
{
    int m = (n >> 1) + (n & 1);
    int i;
    int start, mid, end;
    for (i = 1; i <= m; i <<= 1)
    {
        --n;
        start = 0;
        mid = i - 1;
        end = mid + i;
        (end > n) && (end = n);
        while(mid < end)
        {
            merge(a, start, mid, end);
            start = end + 1;
            mid = start + i - 1;
            end  = mid + i;
            (end > n) && (end = n);
        }
    }
}

void merge(int *a, int start, int mid, int end)
{
    int *temp1 = (int *) malloc((mid - start + 1) * sizeof(int));
    int *temp2 = (int *) malloc((end - mid) * sizeof(int));

    int i, j, length1, length2;
    for(i = 0, j = start; j <= mid; ++i, ++j)
    {
        temp1[i] = a[j];
    }
    length1 = i;

    for(i = 0, j = (mid + 1); j <= end; ++i, ++j)
    {
        temp2[i] = a[j];
    }
    length2 = i;

    int k = start;
    i = 0;
    j = 0;
    while(i < length1 && j < length2)
    {
        if (temp2[j] < temp1[i])
        {
            a[k++] = temp2[j++];
        }
        else
        {
            a[k++] = temp1[i++];
        }
    }

    while(i < length1)
    {
        a[k++] = temp1[i++];
    }

    while(j < length2)
    {
        a[k++] = temp2[j++];
    }
}