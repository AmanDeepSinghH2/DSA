#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}a;

a* insertatpos(a* head,int pos,int data){
    a *new=(a*)malloc(sizeof(a));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    a *temp=head;
    if(pos==1)
    {
        new->next=head;
        new->prev=NULL;
        head=new;
        return head;
    }
    else{
        int i;
        for (i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        new->next=temp->next;
        new->prev=temp;
        temp->next=new;
        temp->next->prev=new;
        return head;
    }   
}

int main(){
    a *head=NULL;
    a *second,*third;
    head=(a*)malloc(sizeof(a));
    second=(a*)malloc(sizeof(a));
    thir=(a*)malloc(sizeof(a));
    head->data=10;
    head->next=second;
    head->prev=NULL;
    second->data=20;
    second->next=third;
    second->prev=head;
    third->data=30;
    third->next=NULL;
    third->prev=second;
    insertatpos(&head,3,40);
    a *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}