#include<stdio.h>
#include<stdlib.h>
struct node
{int data;
struct node *left,*right;
};struct node *start=NULL;
void main()
{
struct node* search(int);
void delete(int);
void insert(int);
int data,option;
struct node *t;

do
{
printf("\n\n---DOUBLY LINKED LIST----\n");
printf("\n1.INSERT\n");
printf("\n2.SEARCH\n");
printf("\n3.DELETE\n");
printf("\n4.EXIT\n");
printf("\nEnter your option:\n");
scanf("%d",&option);
switch(option)
{
case 1:printf("\nEnter the data\n");
scanf("%d",&data);
insert(data);
break;

case 2:printf("\nEnter the data to search:\n");
scanf("%d",&data);
t=search(data);
if(t==(struct node*)0)
{
printf("\nITEM NOT FOUND\n");
}
else
{
printf("\nITEM FOUND\n");
}
break;
case 3:printf("\nEnter the item to delete:\n");
scanf("%d",&data);
delete(data);
printf("Deleted item is:%d",data);
printf("\n");
break;

case 4:exit(1);
}
}
while(1);
}
//function to insert node at begining of doubly linked list
void insert(int data)
{
struct node *t;
t=(struct node*)malloc(sizeof(struct node));
t->data=data;
if(start==(struct node*)0)
{
t->left=t->right=(struct node*)0;
}
else
{t->left=(struct node*)0;
t->right=start;
start->left=t;
}
start=t;
}
struct node* search(int data)
{
struct node *t=start;
while(t!=(struct node*)0 && t->data!=data)
{
t=t->right;
}
return t;
}
void delete(int data)
{
struct node *t;
t=search(data);
if(t==0)
{
printf("\nDATA NOT FOUND\n");
}
else
{
if(t==start) //case of first node
{
if(t->right==(struct node*)0)
start=(struct node*)0;//one and only one node
else
{t->right->left=t->left;//remove 1st node ,more than one node
start=t->right;
}
}
else if(t->right==(struct node*)0)// case of last node
{
t->left->right=t->right;
}
else//case of inter node
{t->left->right=t->right;
t->right->left=t->left;
}
free(t);
}
}
