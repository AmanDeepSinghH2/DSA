#include <stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}l;

l *createnode(int data){
    l *newnode=(l*)malloc(sizeof(l));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

l *insertatpos(l *head,int data,int pos){
    l *newnode=createnode(data);
    if(pos==1){
        newnode->next=head;
        head=newnode;
        return head;
    }
    l *temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}
int main()
{
    l *head=NULL;
    l *second=(l*)malloc(sizeof(l));
    l *third=(l*)malloc(sizeof(l));
    head=(l*)malloc(sizeof(l));
    head->data=10;
    head->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=NULL;
    head=insertatpos(head,40,3);
    l *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}

