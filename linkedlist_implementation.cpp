#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

void insertNode(int data, Node* head, int pos){
    //Function to insert a node in a linkedlist 
    Node* toAdd = new Node();
    toAdd->data=data;

    //Adding node at the begining of linkedlist
    if(pos==0){
        toAdd->next=head;
        head=toAdd;
        return;
    }

    //Adding node at specific position
    Node* prev=head;
    for(int i=0;i<pos-1;i++){
        prev=prev->next;
    }
    toAdd->next=prev->next;
    prev->next=toAdd;
}

void deleteNode(Node* head, int pos){
    //Delete a node from the begining i.e: Delete head of a linkedlist
    if(pos==0){
        head=head->next;
        return;
    }

    //Delete node from specific position
    Node* prev=head;
    for(int i=0;i<pos-1;i++){
        prev=prev->next;
    }
    prev->next=prev->next->next;
}

void printList(Node* head){
    //Function to print linkedlist
    Node* temp = head;
  
    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
  
    // Traverse the list.
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;
	
	head = new Node();
	second = new Node();
	third = new Node();
	
	head->data = 1;
	head->next = second;
	
	second->data=2;
	second->next=third;
	
	third->data=3;
	third->next=NULL;
	printList(head);
	
	insertNode(4,head,3);
	printList(head);
	
	deleteNode(head,2);
	printList(head);
	return 0;
}
