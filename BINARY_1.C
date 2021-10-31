#include<stdio.h>
#include<conio.h>
int binary(int arr[], int l, int r, int x)
{
   while(r >= l)
   {
	int mid = l + (r - l)/2;
	if (arr[mid] == x)
	{
	printf("Element present at index %d\n",mid);
	break;
	}
	if (arr[mid] > x)
	{
	r=mid-1;
	}
	else
	{
	l=mid+1;
	}
   }
}

void main()
{
   int i,n,x,arr[10],res;
   clrscr();
   printf("Enter size of array\n");
   scanf("%d",&n);
   printf("Enter elements of array\n");
   for(i=0;i<n;i++)
   {
   scanf("%d",&arr[i]);
   }
   printf("Enter element to be found\n");
   scanf("%d",&x);
   binary(arr, 0, n-1, x);
   getch();
} 