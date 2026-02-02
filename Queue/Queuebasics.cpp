#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Queue{
    private:
    Node* front;
    Node* rear;

    public:
    Queue() : front(nullptr),rear(nullptr){}

    void enqueue(int data){
        Node* newnode = new Node;
        newnode->data=data;
        newnode->next=nullptr;
        if(front==nullptr){
            front=rear=newnode;
        }
        else{
            rear->next=newnode;
            rear=newnode;
        }

    }
    int dequeue(){
        if(front==nullptr){
            return -1;
        }
        int data=front->data;
        Node* temp=front;
        front=front->next;
        delete temp;
        if(front==nullptr){
            rear=nullptr;
        }
        return data;
    }
    bool isempty(){
        return front==nullptr;
    }
};

int main(){
    Queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    
    return 0;
}