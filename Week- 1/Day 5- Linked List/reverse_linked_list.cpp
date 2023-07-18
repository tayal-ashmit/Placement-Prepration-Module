#include <bits/stdc++.h>
using namespace std;

class ListNode {
  public:
    int val;
    ListNode* next;
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

ListNode* reverseList(ListNode* head) {
    if(head == NULL || head->next==NULL)
        return head;

    ListNode* node= reverseList(head->next);
    head->next->next= head;
    head->next= NULL;

    return node;
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

    ListNode* revList= reverseList(head); 
    
    cout<< "Linked List after reverse:\n";
    printList(revList);

    return 0;
}