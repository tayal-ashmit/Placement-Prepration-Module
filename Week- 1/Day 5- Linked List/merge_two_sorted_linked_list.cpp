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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == NULL)
        return l2;

    if(l2 == NULL)
        return l1;

    if(l1->val > l2->val)
        swap(l1, l2);
    
    ListNode* res=l1;

    while(l1 != NULL && l2 != NULL) {
        ListNode* temp= NULL;

        while(l1 != NULL && l1->val <= l2->val) {
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1, l2);
    }

    return res;
}

void printList(ListNode* head) {
    while(head->next != NULL) {
        cout<< head->val<< "->";
        head= head->next;
    }
    cout<< head->val<< "\n";
}

int main() {
    ListNode* head1= NULL;
    insertNode(head1, 1);
    insertNode(head1, 3);
    insertNode(head1, 5);
    insertNode(head1, 7);

    ListNode* head2= NULL;
    insertNode(head2, 2);
    insertNode(head2, 4);
    insertNode(head2, 6);
    insertNode(head2, 8);

    cout<< "Linked List 1:\n";
    printList(head1);
    cout<< "Linked List 2:\n";
    printList(head2);

    ListNode* newList= mergeTwoLists(head1, head2); 
    
    cout<< "\nLinked List after merging:\n";
    printList(newList);

    return 0;
}