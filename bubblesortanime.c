#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void graph(int n)
{
	int i;
	printf("%d", n);
	for(i=0;i<n;i++)
	{
		printf("--");
	}
		printf("|\n");
}

void delay(unsigned int m)
{
	clock_t goal=m+clock();
	while(goal>clock());
}

void clrscr()
{
    system("@cls||clear");
}


int main()
{
	int a[10]={13,6,3,10,7,4,2,5,8,17},i,j,k;
	
	for(i=0;i<10;i++)
	{
		graph(a[i]);
	}
	delay(1000);
	clrscr();
	
	for(i=0;i<10-1;i++)
	{
		for(j=0;j<10-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]^=a[j+1]^=a[j]^=a[j+1];
			}
			printf("Pass %d\n\n",i+1);
			for(k=0;k<10;k++)
			{
				graph(a[k]);
			}
			delay(1000);
			clrscr();
		}
	}
	printf("After Sorting\n");
	for(i=0;i<10;i++)
	{
		graph(a[i]);
	}
	delay(1000);
	return 0;
}
