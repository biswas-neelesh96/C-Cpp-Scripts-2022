#include <stdio.h>
#include<stdlib.h>
struct stack
{
    int top;
    int size;
    int * arr;
};
int isEmpty(struct stack * s)
{
    if((s->top)==-1)
       { return 1;
       }
    else
    {
        return 0;
}}
int isfull(struct stack * s)
{
    if((s->top)==(s->size)-1)
       { return 1;
       }
    else
    {
        return 0;
}}
void push(struct stack *ptr,int value)
{
    if(isfull(ptr))
    {
        printf("overflow");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=value;
    
}}
int pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("underflow");
    }
    else
    {
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
}}
void print(struct stack *ptr)
{
    for(int i=0;i<=ptr->top;i++)
  {
      printf("%d \n",(ptr->arr)[i]);
  }
}
int main()
{
struct stack * s=(struct stack *)malloc(sizeof(struct stack));
   s->size=80;
   s->top=-1;
   s->arr=(int *)malloc(s->size * sizeof(int));
//   s->arr[0]=7;
//   s->top++;
  push(s,45);
  push(s,55);
  push(s,33);
  pop(s);
//   printf("%d",pop(s));
  print(s);

//   if( isEmpty(s))
//   {
//     printf("empty stack");
//   }
//   else
//   {
//     printf("not empty");
//     }
    return 0;
}
