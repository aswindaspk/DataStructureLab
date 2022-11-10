#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int q[SIZE];
int rear=-1,front=-1; //empty queue
//function to insert an element to a circular queue
void insertq(int item){
int r1=rear;
r1=(r1+1)%SIZE;
if(r1==front)
printf("Queue is full\n");
else
{
rear=r1;
q[rear]=item;}}

//funtion to delete an item from circular queue
int deleteq(int* flag)  //flag is for not prining the return value if queue is empty
{
if(rear==front)
{* flag=0;

printf("Queue is empty\n");}
else{
* flag=1;
front=(front+1)%SIZE;
return q[front];
}
}

//function to search an item in a circular queue
int searchq(int item){
int t;
t=front;
if(front!=rear)//queue is not empty
{
t=(t+1)%SIZE;
while(q[t]!=item && t!=rear)
{
t=(t+1)%SIZE;
}
if(q[t]==item)
return t+1;
else
return 0;}
else
return 0;
}

void main(){
int item,opt,ans,flag;
do{
printf("\n\n-----Enter an option-----\n");
printf("1.Insert\n");
printf("2.Delete\n");
printf("3.Search\n");
printf("4.Exit\n\n");
printf("Enter the option: \n");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("Enter data: \n");
       scanf("%d",&item);
       insertq(item);
       break;
case 2:item=deleteq(&flag);
       if(flag!=0)
       printf("Deleted item is: %d\n\n",item);
       break;
case 3:printf("Item to be searched: \n");
       scanf("%d",&item);
       ans=searchq(item);
       if(ans==0)
       printf("Item not found\n\n");
       else
       printf("Item found in %d(th) location\n\n",ans);
       break;
case 4:exit(0);
}
}
while(1);
}
