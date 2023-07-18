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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *dummy= new ListNode(); 
    ListNode *temp= dummy; 
    int carry=0;

    while((l1 != NULL || l2 != NULL) || carry) {
        int sum=0; 
        if(l1 != NULL) {
            sum += l1->val; 
            l1=l1->next; 
        }
            
        if(l2 != NULL) {
            sum += l2->val; 
            l2=l2->next; 
        }
            
        sum += carry; 
        carry = sum/10; 
        ListNode *node= new ListNode(sum % 10); 
        temp->next=node; 
        temp=temp->next; 
    }

    return dummy->next;
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
    insertNode(head1, 2);
    insertNode(head1, 3);
    insertNode(head1, 4);

    ListNode* head2= NULL;
    insertNode(head2, 2);
    insertNode(head2, 3);
    insertNode(head2, 4);
    insertNode(head2, 5);

    cout<< "Linked List 1:\n";
    printList(head1);
    cout<< "Linked List 2:\n";
    printList(head2);

    ListNode* newList= addTwoNumbers(head1, head2); 
    
    cout<< "\nLinked List after adding:\n";
    printList(newList);

    return 0;
}