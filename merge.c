#include<stdio.h>
#include<conio.h>
void merge(int a[], int beg, int mid, int end)
int i=beg, j=mid+1,k, index = beg:
int temp[101;
while(i<=mid && j‹=end)
{
if (a[i]<a[j])
temp[index] = a[i]:
i = i+1:
}
else
{
temp[index] = a[j];
j=j+1:
}
index++;
}
if (i›mid)
while (j<=end)
temp[index] = a[j]:
index++;
j++;
}
}
else
{
while(i(=mid)
{
temp[index] = a[i]:
index++;
i++
}
}
K = beg;
while(k<index)
{
a[k]=temp[k];
k++;
}
void mergeSort (int arr[], int l, int r)
if (l < r) {
int m = l + (r - l) / 2;
mergeSort (arr, l, m);
mergeSort (arr, m + 1, r);
merge(arr, l, m, r);
}
}

void main()
{
int arr[20],n, i;
clrscr();
printf ("Enter size of the array\n");
scant ("',d" , &n);
printf("Enter elements of the array\n");
for(i=0; i‹n: i++)
{
scanf("/d",&arrti]);
}
mergeSort (arr, 0, n-1);
printf("\nSorted array is \n");
for (1 = 0; 1 < n; 1++)
printf("%d", arr[i]);
printf("\n");
getch();
}