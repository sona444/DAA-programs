#include<stdio.h>
#include<conio.h>
#include<string.h>
struct NODE
{
 int data;
 struct NODE *ptr;
}*start=NULL,*temp,*newnode,*del;

void beginning(int val)
{
 newnode=(struct NODE*)malloc(sizeof(struct NODE));
 if(newnode!=NULL)
 {
 newnode->data=val;
 }
 if(start==NULL)
 {
  start=newnode;
  start->ptr=NULL;
 }
 else
 {
  newnode->ptr=start;
  start=newnode;
 }
}
void end(int val)
{
 int i;
 newnode=(struct NODE*)malloc(sizeof(struct NODE));
 if(newnode!=NULL)
 {
  newnode->data=val;
  newnode->ptr=NULL;
 }
 if(start==NULL)
 {
  start=newnode;
 }
 else if(start->ptr==NULL)
 {
  start->ptr=newnode;
 }
 else
 {
 temp=start;
 while(temp->ptr!=NULL)
 {
  temp=temp->ptr;
 }
 temp->ptr=newnode;
 }
}
void traverse()
{ int i;
  i=0;
  temp=start;
  while(temp->ptr!=NULL)
  {
   printf("pos:%d\tvalue:%d\n",i,temp->data);
   temp=temp->ptr;
   i++;
  }
  printf("pos:%d\tvalue:%d\n",i,temp->data);
}
void any_location(int val, int pos)
{
 int i=0;
 newnode=(struct NODE*)malloc(sizeof(struct NODE));
 if(newnode!=NULL)
 {
  newnode->data=val;
 }
 temp=start;
 while(i<pos-1 && temp!=NULL)
 {
  temp=temp->ptr;
  i++;
 }
 newnode->ptr=temp->ptr;
 temp->ptr=newnode;
}
int del_start()
{
 int del1;
 if(start->ptr==NULL)
 {
  del1=start->data;
  free(start);
 }
 else
 {
  temp=start;
  del1=start->data;
  start=start->ptr;
  free(temp);
 }
 return del1;
}
int del_end()
{
 int del1;
 temp=start;
 if(start->ptr==NULL)
 {
  del1=start->data;
  free(start);
 }
 else
 {
  while(temp->ptr!=NULL)
  {
   del=temp;
   temp=temp->ptr;
  }
  del->ptr=NULL;
  del1=temp->data;
  free(temp);
 }
 return del1;
}

int del_spec(int pos)
{
 int i=0,del1;
 temp=start;
 if(start->ptr==NULL)
 {
  del1=start->data;
  free(start);
 }
 else
 {
 while(i<pos&&temp!=NULL)
 {
  del=temp;
  temp=temp->ptr;
 i++;
 }
 del1=temp->data;
 del->ptr=temp->ptr;
 free(temp);
 }
 return del1;
}
void main()
{
int choice1,choice2,choice3,i,val,del,pos;
char res[5];
clrscr();
do
{
 printf("enter 1 to insertion\nenter 2 for deletion\nenter 3 for traversing");
 scanf("%d",&choice1);
 if(choice1==1)
 {
  printf("enter 1 for insertion at beginning\nenter 2 for insertion at the end\nenter 3 for insertion at any specific index\n");
  scanf("%d",&choice2);
  switch(choice2)
  {
   case 1: printf("enter value to be inserted\n");
  scanf("%d",&val);
  beginning(val);
  break;
   case 2: printf("enter value to be inserted\n");
  scanf("%d",&val);
  end(val);
  break;
   case 3: printf("you list currently looks like this:\n");
  traverse();
  printf("Enter position at which you want to perform insertion\n");
  scanf("%d",&pos);
  printf("enter value to be inserted\n");
  scanf("%d",&val);
  any_location(val,pos);
  break;
  }
 }
 else if(choice1==2)
 {
  printf("enter 1 for deletion at beginning\nenter 2 for deletion at the end\nenter 3 for deletion at any specific index\n");
  scanf("%d",&choice3);
  switch(choice3)
  {
   case 1: del=del_start();
  printf("deleted data = %d\n",del);
  break;
   case 2: del=del_end();
  printf("deleted data = %d\n",del);
  break;
   case 3: printf("you list currently looks like this:\n");
  traverse();
  printf("Enter position at which you want to perform deletion\n");
  scanf("%d",&pos);
  del=del_spec(pos);
  printf("%d deleted\n",del);
  break;
  }
 }
 else
 {
  traverse();
 }
 printf("do you want to work more on this list??\n");
 scanf("%s",&res);
}while(strcmp(res,"y")==0||strcmp(res,"Y")==0);
getch();
}
