#include <stdio.h>
void traverse(int arr[],int size)
{
for( int i=0;i<size;i++)
{
 printf("%d\n",arr[i]);
}
}
int  insert(int arr[],int size,int element,int index,int capacity)
{
   if(size>=capacity)
    {
        return -1;
    }
    for(int i=size-1;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}
void  delete(int arr[],int size,int index)
{
    for(int i=index;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }}

int main() {
int arr[100]={1,2,3,4,5,6,7,88};
int size=8;
insert(arr,size,45,3,100);
printf("array after insertion of 45 at 3rd position");
size=size+1;
traverse(arr,size);
delete(arr,size,5);
size=size-1;
printf("array after deletion of element from 5th position");
traverse(arr,size);
    return 0;
}
