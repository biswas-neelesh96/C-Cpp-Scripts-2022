#include<stdio.h>

void main()
{
    float sum,radius=0;
    printf("Enter the radius of circle:\n");
    scanf("%f",&radius);

    sum = (3.16 * (radius * radius));

    printf("%.2f is the area of the circle\n",sum);
}
