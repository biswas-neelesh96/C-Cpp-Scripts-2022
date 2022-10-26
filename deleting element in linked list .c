Deletion operation In linked list
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
void linkedlisttraverse(struct node *ptr)
{
    while(ptr != NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
} 
struct node * deletionatstart(struct node* head)
{
    struct node *p=head;
    head=head->next;
    free(p);
    return head;
}
struct node * deletinatgivenindex(struct node * head,int index)
{
 struct node *ptr=head;   
 struct node *q=ptr->next;
 for(int i=0;i<index-1;i++)
 {
     ptr=ptr->next;
     q=q->next;
 }
 ptr->next=q->next;
free(q);
return head;
}
struct node * deletinatlast(struct node * head)
{
 struct node *ptr=head;   
 struct node *q=ptr->next;
 while (q->next !=NULL)
 {
     ptr=ptr->next;
     q=q->next;
 }
 ptr->next=NULL;
free(q);
return head;
}
int main ()
{
     struct node * head;
     struct node * second;
      struct node * third;
       struct node * fourth;
        struct node * fifth;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));
    fifth=(struct node*)malloc(sizeof(struct node));
    head->data=7;
    head->next=second;
    second->data=9;
    second->next=third;
    third->data=10;
    third->next=fourth;
    fourth->data=43;
    fourth->next=fifth;
    fifth->data=6;
    fifth->next=NULL;
    linkedlisttraverse(head);
    head=deletionatstart(head);
    printf("deletion from start");
    linkedlisttraverse(head);
    head=deletinatgivenindex(head,1);
    printf("deletion at given index \n");
    linkedlisttraverse(head);
    head=deletinatlast(head);
    printf("deletion at last \n");
    linkedlisttraverse(head);
    
    


  return 0;
}
