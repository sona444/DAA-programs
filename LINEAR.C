#include<stdio.h>
#include<conio.h>
void main()
{
int arr[25],n,i,x;
clrscr();
printf("enter size of array you want");
scanf("%d",&n);
printf("enter elements of the array");
for(i=0;i<n;i++)
{
 scanf("%d",&arr[i]);
}
printf("enter element to be searched");
scanf("%d",&x);
for(i=0;i<n;i++)
{
 if(arr[i]==x)
 {
 printf("element found at index %d",i);
 break;
 }
}
getch();
}
