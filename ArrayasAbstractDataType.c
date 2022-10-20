#include <stdio.h>

#include<stdlib.h>

struct myarray

{

    int totalsize;

    int usedsize;

    int *ptr

};

void create(struct myarray *a,int tsize,int usize)

{

a->totalsize=tsize;

a->usedsize=usize;

a->ptr=(int*)malloc(tsize*sizeof(int));

}

void display(struct myarray *a)

{

    int m;

    for( int i=0;i<a->usedsize;i++)

   {

       m=(a->ptr)[i];

       printf("%d",m);

      

   }

}

 

void get(struct myarray *a)

{

    int n;

    printf("enter element");

    for(int i=0;i<a->usedsize;i++)

{

    scanf("%d",&n);

    (a->ptr[i])=n;

}

   

}

int main() {

    struct myarray marks;

    create(&marks,10,4);

    get(&marks);

    display(&marks);

 

    return 0;

}
