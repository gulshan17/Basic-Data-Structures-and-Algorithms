#include<iostream>
using namespace std;
class sort
{
	int a[10];

public:sort()
		{
			int i;
			a[0] =23 ;
			a[1] = 5;
			a[2] = 2;
			a[3] = 4;
			a[4] = 1;
			a[5] = 7;
			a[6] = 34;
			a[7] = 98;
			a[8] = 213;
			a[9] = 17;
		}

	   void qsort(int l, int r)
	   {
		   int x = a[(l + r) / 2], i = l, j = r;
		   
		   do
		   {
			   while ((x > a[i]) && (i < r))
			   {
				   i++;
			   }
			   while ((x < a[j]) && (j > l))
			   {
				   j--;
			   }
			   if (i <= j)
			   {
				   if (i ^ j)
				   {
					   a[i] ^= a[j] ^= a[i] ^= a[j];
				   }
				   i++;
				   j--;
			   }
		   } while (i <= j);

		  if (l < j)
		   {
			   qsort(l, j);
		   }
		   if (r > i)
		   {
			   qsort(i, r);
		   }
	   }

	   void ssort()
	   {
		   int i,k;
		   register int temp, j;
		   for (i = 0; i < 9; i++)
		   {
			   k = i;
			   temp = a[i];
			   for (j = i + 1; j <= 9; j++)
			   {
				   if (temp > a[j])
				   {
					   temp = a[j];
					   k = j;
				   }
			   }
			   if (k != i)
			   {
				   a[i] ^= a[k] ^= a[i] ^= a[k];
			   }
		   }
	   }

	   void isort()
	   {
		   int i;
		   register int j, k;
		   for (i = 0; i < 9; i++)
		   {
			   k = i;
			   j = i + 1;
			   while ((a[j] < a[k]) && (j>0))
			   {
				   a[k] ^= a[j] ^= a[k] ^= a[j];
				   j--;
				   k--;
			   }
		   }
	   }

	   void merge(int left, int mid, int right)
	   {
		   int i=left,j=right,x;
		   int *temp1=new int[mid-left+2],*temp2=new int[right-mid+1];
		   int z=0,y=0;
		   for (i = left,z=0; i <= mid; i++,z++)
		   {
			   temp1[z] = a[i];
		   }
		   temp1[z] =9999999999;
		   for (i = mid+1,y=0; i <= right; i++, y++)
		   {
			   temp2[y] = a[i];
		   }
		   temp2[y] = 9999999999;
		   i = 0;
		   j = 0;
		   x = left;
		   while ((i < z)||(j < y))
		   {
			   if (temp1[i] <= temp2[j])
			   {
				   a[x] = temp1[i];
				   i++;
				   x++;
			   }
			   else
			   {
				   a[x] = temp2[j];
				   j++;
				   x++;
			   }
		   }
	   }
	   void mergesort(int left, int right)
	   {
		   if (left < right)
		   {
			   int mid = (left + right) / 2;
			   mergesort(left, mid);
			   mergesort(mid + 1, right);
			   merge(left, mid, right);
		   }
	   }

	   void display()
	   {
		   int i;
		   for (i = 0; i < 10; i++)
		   {
			   cout << a[i]<<endl;
		   }
	   }

};
int main()
{
	sort obj;
	obj.display();
	cout << "after sorting\n";
	obj.qsort(0, 9);
	//obj.ssort();
	//obj.isort();
	//obj.mergesort(0, 9);
	obj.display();
	return 0;
}
