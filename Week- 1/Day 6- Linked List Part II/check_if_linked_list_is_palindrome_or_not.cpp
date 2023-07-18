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

bool isPalindrome(ListNode* head) {
    vector<int> arr;
    while(head != NULL) {
        arr.push_back(head->val);
        head = head->next;
    }

    int n=arr.size();
    for(int i=0; i<n/2; i++)  {
        if(arr[i] != arr[n-i-1])
            return false;
    }
    return true;
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
    insertNode(head, 2);
    insertNode(head, 1);
    
    cout<< "Linked List\n";
    printList(head);

    cout<< "\nLinked List is Palindrome: ";
    isPalindrome(head) ? cout<< "True" : cout<< "False";

    return 0;
}