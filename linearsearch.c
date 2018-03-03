#include<stdio.h>

int main()
{
	int n; 
	printf("Enter the number of elements in the array:\n");
	scanf("%d",&n);
	int a[n],item,found=0,i;
	printf("Please enter the elements in the array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be searched");
	scanf("%d",&item);
	for(i=0;i<n;i++)
	{
		if(!(a[i]^item))
		{
			found=1;
			break;
		}
	}
	if(found)
	{
		printf("Search successful\n");
	}
	
	else
	{
		printf("sorry but the search is unsuccessful\n");
	}
	return 0;
}
