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

int lengthOfLinkedList(ListNode* head) {
    int length=0;
    while(head != NULL) {
        ++length;
        head= head->next;
    }
    return length;
}

ListNode* reverseKNodes(ListNode* head,int k) {
    if(head == NULL||head->next == NULL)
        return head;
    
    int length= lengthOfLinkedList(head);
    
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    
    ListNode* pre = dummyHead;
    ListNode* cur;
    ListNode* nex;
    
    while(length >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }

    return dummyHead->next;
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
    int k=3;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    insertNode(head, 6);
    insertNode(head, 7);
    insertNode(head, 8);

    cout<< "Linked List\n";
    printList(head);

    ListNode* newList= reverseKNodes(head, k);

    cout<< "\nLinked List after reversal in groups of k nodes\n"; 
    printList(newList);

    return 0;
}