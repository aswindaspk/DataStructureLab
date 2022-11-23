#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node * next;};
struct node * sp=(struct node *)0;

//function to push an item from stack
void push(int item){
struct node * t;
t=(struct node *)malloc(sizeof(struct node *));
t->data=item;
t->next=sp;
sp=t;
return;}


//function to pop an item from stack
int pop(int * flag)
{
struct node * t;
int item;
if(sp==(struct node *)0){
* flag=0;
printf("Empty Stack");}
else{
* flag=1;
item=sp->data;
t=sp;
sp=sp->next;
free(t);
return item;}
}

//function to search an item from stack
int search(int item){
int count=0;
struct node * t=sp;
while(t!=(struct node *)0){
++count;
if(t->data==item)
return count;
t=t->next;}
return 0;
}

void main(){
int item,opt,ans,flag;
do{
printf("\n\n----Options----\n");
printf("1.Push\n");
printf("2.Pop\n");
printf("3.Search\n");
printf("4.Exit\n");
printf("\nOption: \n");
scanf("%d",&opt);


switch(opt){
case 1:printf("\nData: ");
       scanf("%d",&item);
       push(item);
       break;


case 2:item=pop(&flag);
       if(flag!=0)
       printf("\nDeleted %d \n",item);
       break;

case 3:printf("\nNumber to be searched:\n");
       scanf("%d",&item);
       ans=search(item);
       if(ans==0)
       printf("\nItem not found\n");
       else
       printf("\nFound at %d(th) position\n",ans);
       break;

case 4:exit(0);
}
}
while(1);
}
