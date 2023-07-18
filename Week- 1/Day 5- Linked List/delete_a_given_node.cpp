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

ListNode* getNode(ListNode* head,int x) {
    while(head->val != x)
        head = head->next;
    
    return head;
}

void deleteNode(ListNode* t) {
    t->val = t->next->val;
    t->next = t->next->next;
    return;
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

    ListNode* t= getNode(head, 2);
    deleteNode(t);
    
    cout<< "Linked List after deletion:\n";
    printList(head);

    return 0;
}