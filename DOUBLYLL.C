#include<stdio.h>
#include<conio.h>
struct NODE
{
 int data;
 struct NODE *next,*prev;
}*start=NULL,*temp,*newnode,*del1;
void beginning(int val)
{
newnode=(struct NODE*)malloc(sizeof(struct NODE));
if(newnode==NULL)
{
 printf("No space in memory\n");
}
else
{
 newnode->data=val;
}
if(start==NULL)
{
start=newnode;
start->next=NULL;
start->prev=NULL;
}
else
{
 newnode->next=start;
 newnode->prev=NULL;
 start->prev=newnode;
 start=newnode;
}
}
void end(int val)
{
 newnode=(struct NODE*)malloc(sizeof(struct NODE));
 if(newnode==NULL)
 {
  printf("not enough space\n");
 }
 else
 {
  newnode->data=val;
 }
 if(start==NULL)
 {
  start=newnode;
  start->next=NULL;
  start->prev=NULL;
 }
 else
 {
  temp=start;
  while(temp->next!=NULL)
  {
   temp=temp->next;
  }
  newnode->next=NULL;
  temp->next=newnode;
  newnode->prev=temp;
 }
}
void any_position(int val,int pos)
{
 newnode=(struct NODE*)malloc(sizeof(struct NODE));
 if(newnode==NULL)
 {
  printf("not enough space\n");
 }
 else
 {
  newnode->data=val;
 }
 if(start==NULL)
 {
  start=newnode;
  start->next=NULL;
 }
 else
 {
 int i=0;
 temp=start;
 while(i<pos-1&&temp!=NULL)
 {
  temp=temp->next;
  i++;
 }
 if(temp==NULL)
 {
  printf("position exceeding number of nodes\n");
 }
 else
 {
  newnode->next=temp->next;
  newnode->prev=temp;
  (temp->next)->prev=newnode;
  temp->next=newnode;
 }
 }
}
int del_start()
{
 int del;
 temp=start;
 del=temp->data;
 (temp->next)->prev=NULL;
 temp=temp->next;
 free(start);
 start=temp;
 return del;
}
int del_end()
{
 int del;
 struct NODE *del1;
 if(start==NULL)
 {
  printf("nothing to delete\n");
 }
 else
 {
 temp=start;
 while(temp->next!=NULL)
 {
  del1=temp;
  temp=temp->next;
 }
 del1->next=NULL;
 del=temp->data;
 free(temp);
 }
 return del;
}
int del_spec(int pos)
{
 int del,i;
 i=0;
 temp=start;
 if(start->next==NULL)
 {
  del=start->data;
  free(start);
 }
 else
 {
 while(i<pos && temp->next!=start)
 {
  del1=temp;
  temp=temp->next;
  i++;
 }
 del1->next=temp->next;
 (temp->next)->prev=del1;
 del=temp->data;
 free(temp);
 return del;
 }
}
void traverse()
{
 int i=0;
 temp=start;
 printf("index\tdata\n");
 while(temp->next!=NULL)
 {
  printf("%d\t%d\n",i,temp->data);
  temp=temp->next;
  i++;
 }
  printf("%d\t%d\n",i,temp->data);
}
void main()
{
 int choice1,choice2,choice3,i,val,del,pos;
char res[5];
clrscr();
printf("sonakshi\n1/19/FET/BCS/197\n");
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
  any_position(val,pos);
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
  printf("Enter position at which you want to perform insertion\n");
  scanf("%d",&pos);
  del_spec(pos);
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
