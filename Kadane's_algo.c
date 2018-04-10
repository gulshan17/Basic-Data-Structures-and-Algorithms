/*This program uses Kadane's algo to compute the maximum sum in the subarray*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	printf("Please Enter the number of elements in the array: ");
	scanf("%d", &n);
	
	int *a = malloc(n * sizeof(int)), current_max, global_max, i;
	
	printf("Please Enter the elements in the array\n");
	i = 0;
	while(i ^ n)
	{
		scanf("%d", (a + (i++)));
	}
	
	i = 1;
	current_max = global_max = *(a);
	while(i ^ n)
	{
		current_max = (current_max + (*(a + i))) > a[i] ? (current_max + (*(a + i))) : a[i];

		((current_max > global_max) && (global_max = current_max));
		++i;
	}
	
	printf("The maximum sum of subarray = %d\n", global_max);
	
	return 0;
}