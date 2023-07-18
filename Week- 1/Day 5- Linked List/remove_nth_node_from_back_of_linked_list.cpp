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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* start= new ListNode();
    start->next= head;
    ListNode* fast= start;
    ListNode* slow= start;     

    for(int i=1; i<=n; ++i)
        fast= fast->next;
    
    while(fast->next != NULL) {
        fast= fast->next;
        slow= slow->next;
    }
        
    slow->next = slow->next->next;
        
    return start->next;
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

    ListNode* newList= removeNthFromEnd(head, 2);
    
    cout<< "Linked List after removing 2 node from end:\n";
    printList(newList);

    return 0;
}