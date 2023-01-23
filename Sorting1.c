#include<stdio.h>
void main()
{
int arr1[20],arr2[20],arr3[40];
void read_array(int[], int);
void print_array(int[], int);
void merge(int[], int[],int[], int,int);
int m,n;
printf("Enter no. of Elements of 1st array: ");
scanf("%d",&m);
read_array(arr1,m);
printf("\nEnter no. of Elements of 2nd array: ");
scanf("%d",&n);
read_array(arr2,n);
merge(arr1,arr2,arr3,m,n);
print_array(arr3,m+n);
}

//function to read elements of array
void read_array(int arr[], int x){
int i;
printf("Enter the Elements:\n");
for(i=0;i<x;i++){
scanf("%d",&arr[i]);}}

//function to print elements of array
void print_array(int arr[], int x){
int i;
printf("\nSorted Elements are:\n");
for(i=0;i<x;i++){
printf("%d\n",arr[i]);}}

//functions to merge two sorted arrays
void merge(int a[], int b[], int c[], int x, int y){
int i=0,j=0,k=0;
while(i<x&&j<y){
if(a[i]<b[j])
{
c[k]=a[i];
i=i+1;
k=k+1;}
else{
c[k]=b[j];
j=j+1;
k=k+1;}}
while(i<x){
c[k++]=a[i++];} //if any elements are left in the 1st array
while(j<y){
c[k++]=b[j++];}} //if any elements are left in the 2nd array
