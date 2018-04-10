#include<stdio.h>
#include<stdlib.h>

void rand_quicksort(int *, int, int);

int main()
{
  int a[] = {23, 5, 2, 4, 1, 7, 17, 17, 34, 98, 213, 17};

  rand_quicksort(a, 0, 11);

  printf("The sorted elements are:\n");

  for(int i = 0; i ^ 10; ++i)
  {
    printf("%d\n", a[i]);
  }

  return 0;
}

void rand_quicksort(int *a, int left, int right)
{
  if(left >= right)
  {
    return;
  }

  //printf("The value of left = %d\nThe value of right = %d\n", left, right);
  int i = left + 1, j;
  //printf("Pivot is getting initialiased\n");
  int piv_id = (left + (rand() % ((right - left) + 1))), pivot;
  pivot = a[piv_id];
 // printf("The value of pivot index is %d\nThe value of pivot is %d\n", piv_id, pivot);
  //getchar();

	((a[piv_id] ^ a[left]) && (a[left] ^= a[piv_id] ^= a[left] ^= a[piv_id]));
	
  for(j = left + 1; j <= right; ++j)
  {
    if(a[j] <= pivot)
    {
		((a[i] ^ a[j]) && (a[i] ^= a[j] ^= a[i] ^= a[j]));
		++i;
    }
  }

  ((a[left] ^ a[i - 1]) && (a[left] ^= a[i - 1] ^= a[left] ^= a[i - 1]));

  rand_quicksort(a, left, i - 2);
  rand_quicksort(a, i, right);
}
