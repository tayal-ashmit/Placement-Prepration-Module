#include<bits/stdc++.h>
using namespace std;

class Stack {
    int size;
    int* arr;
    int top;

 public:
    Stack() {
        top= -1;
        size= 1000;
        arr= new int[size];
    }

    void push(int x) {
        top++;
        arr[top]= x;
    }

    int pop() {
        int x= arr[top];
        top--;
        return x;
    }

    int top() {
        return arr[top];
    }

    int size() {
        return top+1;
    }
};

int main() {
    Stack s;
    s.push(4);
    s.push(5);
    s.push(6);

    cout<< "Element at the top of stack: "<< s.top()<< endl;
    cout<< "Size of stack: "<< s.size()<< endl;
    cout<< "The element deleted: "<< s.pop()<< endl;
    cout<< "Size of stack: "<< s.size()<< endl;
    cout<< "Element at the top of stack: "<< s.top()<< endl;
    
    return 0;
}