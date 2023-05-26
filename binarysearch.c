#include<stdio.h>

void binarysearch(int *a,int lower,int mid,int upper,int item);
int flag=0;

int main()
{
	int n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int a[n],lower=0,upper=n-1,i;
	printf("Please enter the elements in the array in a sorted way\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the item you want to search:");
	scanf("%d",&i);
	binarysearch(a,lower,mid,upper,i);
	if(flag)
	{
		printf("Search successfuly\n");
	}
	else
	{
		printf("Search unsuccessful\n");
	}
	return 0;
}

void binarysearch(int *a,int lower,int upper,int item)
{
	mid = (lower  + upper) >> 1;
	while(lower<=upper)
	{
		if(a[mid]==item)
		{
			flag=1;
			return;
		}
		else if(item<a[mid])
		{
			upper=mid-1;
			binarysearch(a,lower,upper,item);
		}
		else
		{
			lower=mid+1;
			binarysearch(a,lower,upper,item);
		}
	}
}
