#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}N;

N*createnode(int data){
    N*newnode=(int*)malloc(sizeof(int));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

N*insertatb(N*head,int data){
    N*newnode=createnode(data);
    newnode->next=head;
    return newnode;
}
N*insertatp(N*head,int data,int pos){
    N*newnode=createnode(data);
    N*temp=head;
    for(int i=1;i<=pos-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}
N*insertatend(N*head,int data){
    N*newnode=createnode(data);
    N*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
    return head;
}
N*deleteatb(N*head){
    N*temp=head;
    head=head->next;
    free(temp);
    return head;
}

N*deleteatp(N*head,int pos){
    N*temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    N*nodeToDelete=temp->next;
    temp->next=nodeToDelete->next;
    free(nodeToDelete);
    return head;
}

N*deleteatend(N*head){
    N*temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    N*last=temp->next;
    temp->next=NULL;
    free(last);
    return head;
}

void display(N*head){
    N*temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    N*head=NULL;
    head=insertatb(head,10);
    head=insertatb(head,20);
    head=insertatb(head,30);
    head=insertatb(head,40);
    head=insertatb(head,50);
    display(head);
    head=deleteatb(head);
    display(head);
    head=insertatp(head,100,2);
    display(head);
    head=deleteatp(head,2);
    display(head);
    head=insertatend(head,1000);
    display(head);
    head=deleteatend(head);
    display(head);
    return 0;
}