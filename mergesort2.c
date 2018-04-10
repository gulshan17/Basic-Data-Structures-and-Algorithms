#include<stdio.h>

void mergesort(int *, int, int);
void merge(int *, int, int, int);

int main()
{
  int a[] = {23, 5, 2, 4, 1, 7, 17, 17, 34, 98, 213, 17};

  mergesort(a, 0, 11);

  printf("The sorted elements are:\n");

  for(int i = 0; i ^ 10; ++i)
  {
    printf("%d\n", a[i]);
  }

  return 0;
}

void mergesort(int *a, int left, int right)
{
	if(left < right)
	{
		int mid = (right + left)/2;
		
		mergesort(a, left, mid);
		mergesort(a, mid + 1, right);
		
		merge(a, left, mid, right);
	}
}

void merge(int *a, int left, int mid, int right)
{
	int lpos = left, rpos = right, temp_a[right - left + 1], pos = 0;
	
	while((lpos <= mid) && (rpos <= right))
	{
		if(a[lpos] <= a[rpos])
		{
			temp_a[lpos++] = a[lpos++];
		}
		
		else
		{
			temp_a[pos++] = a[rpos++];
		}
	}
	
	while(lpos <= mid)
	{
		temp_a[pos++] = a[lpos++];
	}
	
	while(rpos <= right)
	{
		temp_a[pos++] = a[rpos++];
	}
	
	pos = 0;
	while(left <= right)
	{
		a[left++] = temp_a[pos++];
	}
}
