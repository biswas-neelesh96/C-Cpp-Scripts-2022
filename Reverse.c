#include<stdio.h>
int main()
{
    int p,m,n,rev=0;          //initializing rev as 0, as well declaring p,m & n as integers
    printf("Enter a number"); //declaring n to read number
    scanf("%d",&n);
    p=n;                      //copy the number from n to p to print the value as well as the value of n will change
    //working of the program
    while(n>0)
    {
       m=n%10;
       rev=rev*10+m;
       n=n/10;
    }
    printf("Reverse of %d = %d",p,rev);
    return 0;
}
