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

ListNode* intersectionPresent(ListNode* head1, ListNode* head2) {
    while(head2 != NULL) {
        ListNode* temp = head1;
        while(temp != NULL) {
            if(temp == head2)
                return head2;
            temp=temp->next;
        }
        head2 = head2->next;
    }
    return NULL;
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
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 4);

    ListNode* head1 = head;

    head= head->next->next->next;
    ListNode* headSec= NULL;
    insertNode(headSec, 3);

    ListNode* head2= headSec;
    headSec->next= head;
    
    cout<< "Linked List 1\n";
    printList(head1);
    cout<< "Linked List 2\n";
    printList(head2);
    
    ListNode* answerNode= intersectionPresent(head1, head2);
    if(answerNode == NULL )
        cout<< "\nNo intersection";
    else
        cout<< "\nThe intersection point is " <<answerNode->val;
    
    return 0;
}