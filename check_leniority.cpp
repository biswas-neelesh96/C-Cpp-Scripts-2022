#include<stdio.h>
#include<conio.h>
int main()
{
	int x1,x2,x3,y1,y2,y3;
	scanf("%d%d%d%d%d%d",&x1,&x2,&x3,&y1,&y2,&y3);
	printf("the value of (x1,y1)%d,%d",x1,y1);
	printf("\n the value of (x2,y2)%d,%d",x2,y2);
	printf("\n the value of (x3,y3)%d,%d",x3,y3);
	if(x1*y2-x2*y3-x2*y1+x2*y3+x3*y1-y2*x3==0)
	{
	printf("\n the point are collinier");
	}
	else
	printf("\n the point are non colliner");
	}
	
