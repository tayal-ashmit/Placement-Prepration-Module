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

void createCycle(ListNode* &head, int a, int b) {
    int cnta=0;
    int cntb=0;
    ListNode* p1=head;
    ListNode* p2=head;

    while(cnta != a || cntb != b) {
        if(cnta != a)
            p1=p1->next, ++cnta;
        if(cntb != b)
            p2=p2->next, ++cntb;
    }

    p2->next=p1;
}

bool cycleDetect(ListNode* head) {
    unordered_set<ListNode*> hash;
    while(head != NULL) {
        if(hash.find(head) != hash.end())
            return true;
        hash.insert(head);
        head= head->next;
    }
    return false;
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
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);

    createCycle(head, 1, 3);

    if(cycleDetect(head) == true)
        cout<< "Cycle detected\n";
    else
        cout<< "Cycle not detected\n";

    return 0;
}