#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Stack{
    Node* top;

    public:
    Stack() : top(nullptr){}

    void push(int data){
        Node* newNode = new Node;
        newNode->data=data;
        newNode->next=top;
        top=newNode;
    }

    int pop(){
        if(top==nullptr){
            return -1;
        }
        int data=top->data;
        Node* temp=top;
        top=top->next;
        delete temp;
        return data;
    }

    int peek(){
        if(top==nullptr){
            return -1;
        }
        return top->data;
    }
    bool isempty(){
        return top==nullptr;
    }

};