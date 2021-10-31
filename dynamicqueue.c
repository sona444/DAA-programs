#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct NODE
{
 int data;
 struct NODE *ptr;
}*front=NULL,*rear=NULL,*newnode,*temp;
void insert(int val)
{
 newnode=(struct NODE*)malloc(sizeof(struct NODE));
 if(newnode==NULL)
 {
  printf("No space in memory");
 }
 else
 {
  newnode->data=val;
 }
 if(front==NULL)
 {
  front=newnode;
  rear=newnode;
  rear->ptr=NULL;
 }
 else
 {
  newnode->ptr=NULL;
  rear->ptr=newnode;
  rear=newnode;
 }
}
int del()
{
 int del1;
 if(front==NULL)
 {
  printf("nothing to delete");
 }
 else
 {
  temp=front;
  del1=front->data;
  front=front->ptr;
  free(temp);
 }
 return del1;
}

void traverse()
{
 for (temp=front;temp!=rear;temp=temp->ptr)
 {
  printf("%d",temp->data);
 }
 printf("%d",temp->data);
}
void main()
{
 int choice,val,del1;
 char choice2[10];
 clrscr();
 do
 {
 printf("enter 1 for insertion, 2 for deletion and 3 for traversing\n");
 scanf("%d",&choice);
 if(choice==1)
 {
  printf("enter value to be inserted in the queue\n");
  scanf("%d",&val);
  insert(val);
  printf("%d inserted\n",val);
 }
 else if(choice==2)
 {
  printf("currently your queue looks like this\n");
  traverse();
  del1=del();
  printf("\n%d deleted\n",del1);
 }
 else
 {
  traverse();
 }
 printf("do you want to work more on your queue?\n");
 scanf("%s",&choice2);
 }while(strcmp(choice2,"y")==0);
 getch();
}
