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
 for(j=0;j<size-1;j++)
 {
  for(k=0;k<size-j-1;k++)
  {
  if(arr[k]>arr[k+1])
  {
   swap=arr[k];
   i++;
   arr[k]=arr[k+1];
   i++;
   arr[k+1]=swap;
   i++;
  }
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