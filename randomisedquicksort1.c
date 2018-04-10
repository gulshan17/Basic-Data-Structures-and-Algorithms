#include<stdio.h>
#include<stdlib.h>

void quicksort(int  *a, int left, int right)
{
	int i = left, j = right, pivot = a[left + (rand() % (right - left + 1))];
	//printf("left = %d\nright = %d\n", left, right);
	//getchar();

	do
	{
		while( ((* (a + i) ) < pivot) && (i < right) )
		{
			i++;
		}

		while( ((* (a + j) ) > pivot) && (j > left) )
		{
			j--;
		}

		if(i <= j)
		{
			if(a[i] ^ a[j])
			{
				a[i] ^= a[j] ^= a[i] ^= a[j];
			}

			i++;
			j--;
		}

	}while(i <= j);

	if(left < j)
	{
		quicksort(a, left, j);
	}

	if(i < right)
	{
		quicksort(a, i, right);
	}
}

int main()
{
	int a[] = {23, 5, 2, 4, 1, 7, 17, 17, 34, 98, 213, 17};
	//printf("Please enter the elements of the array\n");

	/*for(int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}*/

	//printf("Now Starting quicksort\n");
	quicksort(a, 0,11);

	printf("after sorting the array will look like as\n");

	for(int i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	}

	return 0;
}
