#include<stdio.h>

void quicksort(int *a, int, int);

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

void quicksort(int *a, int start, int end) {
	int i = start, j = end, pivot = ((start + end)/2);
	if(end > start){
		while(i < j){	
			while((a[i] <= a[pivot]) && (i < pivot))
				i++;
			while((a[j] >= a[pivot]) && (j > pivot))
				j--;
			if(a[i] ^ a[j]){
				a[i] ^= a[j] ^= a[i] ^= a[j];
			}
			if(i == pivot)
				pivot = j;
			else if(j == pivot)
				pivot = i;
		}
		quicksort(a, start, pivot - 1);
		quicksort(a, pivot + 1, end);
	}
}