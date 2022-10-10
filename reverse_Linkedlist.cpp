#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};


//Iterative approach
Node* reverseList1(Node* head){
    Node* cur = head;
    Node* prev = NULL;
    while(cur!=NULL){
        Node* temp = cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    return prev;
}


//Recursive approach
Node* reverseList2(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newHead = reverseList2(head->next);
    Node* headNext = head->next;
    headNext->next = head;
    head->next = NULL;
    return newHead;
}

void printList(Node* head){
    Node* temp = head;
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
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
	
	Node* node1 = reverseList1(head);
	printList(node1);

    // Node* node2 = reverseList2(head);
	// printList(node2);

	return 0;
}
