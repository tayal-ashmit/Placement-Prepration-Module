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

void createCycle(ListNode* &head, int pos) {
    ListNode* ptr= head;
    ListNode* temp= head;
    int cnt=0;
    while(temp->next != NULL) {
        if(cnt != pos) {
            ++cnt;
            ptr= ptr->next;
        } 
        temp= temp->next;
    }
    temp->next= ptr;
}

ListNode* detectCycle(ListNode* head) {
    unordered_set<ListNode*> st;
    while(head != NULL) {
        if(st.find(head) != st.end())
            return head;
        st.insert(head);
        head= head->next;
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
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 3);
    insertNode(head, 6);
    insertNode(head, 10);

    createCycle(head, 2);

    ListNode* node= detectCycle(head);
    if(node == NULL)
        cout<< "No cycle";
    else {
        ListNode* temp= head;
        int pos=0;
        while(temp != node) {
            ++pos;
            temp= temp->next;
        }
        cout<< "Tail connects at pos- "<< pos;
    }

    return 0;
}