#include<stdio.h>

void quicksort(int *, int, int);

int main()
{
  int a[] = {23, 5, 2, 4, 1, 7, 17, 17, 34, 98, 213, 17};

  quicksort(a, 0, 11);

  printf("The sorted elements are:\n");

  for(int i = 0; i ^ 10; ++i)
  {
    printf("%d\n", a[i]);
  }

  return 0;
}

void quicksort(int *a, int left, int right)
{
  if(left >= right)
  {
    return;
  }

  int i = left + 1, j;

  for(j = left + 1; j <= right; ++j)
  {
    if(a[j] < a[left])
    {
      if(a[i] ^ a[j])
      {
        a[i] ^= a[j] ^= a[i] ^= a[j];
      }
      ++i;
    }
  }

  //--i;
  if(a[left] ^ a[i - 1])
  {
    a[left] ^= a[i - 1] ^= a[left] ^= a[i - 1];
  }

  quicksort(a, left, i - 2);
  quicksort(a, i, right);
}
