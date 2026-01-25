#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* Next;
};

class solution{
    public:
    int lengthofLL(Node* head){
        int count=0;
        Node* temp = head;
        while(temp->Next!=NULL){
            count++;
            temp=temp->Next;
        }
        return count;
    }
};