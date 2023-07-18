#include <bits/stdc++.h>
using namespace std;

class ListNode {
  public:
    int val;
    ListNode* next;
    ListNode() {
        val=0;
        next= NULL;
    }
    ListNode(int a) {
        val = a;
        next = NULL;
    }
    ListNode(int x, ListNode *next) {
        val= x;
        next= next;
    }
};

void insertNode(ListNode* &head, int x) {
    ListNode* newNode = new ListNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }

    ListNode* temp= head;
    while(temp->next != NULL)
        temp=temp->next;
    
    temp->next = newNode;
}

ListNode* middleNode(ListNode* head) {
   	int n=0;
 	ListNode* temp= head;
	while(temp) {
        n++;
    	temp=temp->next;
   	}
   	
   	temp=head;
   	for(int i=0; i<n/2; i++) {
    	temp=temp->next;
    }
   	
	return temp;
}

void printList(ListNode* head) {
    while(head->next != NULL) {
        cout<< head->val<< "->";
        head= head->next;
    }
    cout<< head->val<< "\n";
}

int main() {
    ListNode* head= NULL;
    insertNode(head, 1);
    insertNode(head, 4);
    insertNode(head, 2);
    insertNode(head, 3);

    cout<< "Linked List:\n";
    printList(head);

    ListNode* newList= middleNode(head);
    
    cout<< "Middle of Linked List:\n";
    printList(newList);

    return 0;
}