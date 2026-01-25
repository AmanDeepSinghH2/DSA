#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
};

class Solution {
public:
    bool Search(Node* head,int target) {
        Node* temp=head;
        while(temp->next!=NULL){
            if(temp->val==target){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
};