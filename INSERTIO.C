#include<stdio.h>
#include<conio.h>
void main()
{
 int i=0,j,size,swap,k,temp;
 int arr[100];
 clrscr();
 printf("Enter size of the array");
 scanf("%d",&size);
 printf("Enter elements of the array");
 for(j=0;j<size;j++)
 {
  scanf("%d",&arr[j]);
 }
 for(j=1;j<size;j++)
 {
  k=j;
  while(k>0 && arr[k-1]>arr[k])
  {
   temp=arr[k];
   i++;
   arr[k]=arr[k-1];
   i++;
   arr[k-1]=temp;
   i++;
   k--;
   i++;
  }
 }
 printf("sorted array= ");
 i++;
 for(j=0;j<size;j++)
 {
  printf("%d ",arr[j]);
  i++;
 }
 printf("\nNo. of lines executed are %d",i);
 getch();
}