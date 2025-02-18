#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}L;

L* insertend(L* start,int data)
{
    L* newnode=(L*)malloc(sizeof(L));
    L* temp=start;
    newnode->data=data;
    newnode->next=NULL;
    if(start==NULL)
    {
        start=newnode;
        return start;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return start;
}
int main()
{
    L *head=NULL;
    L *second,*third;
    head=(L*)malloc(sizeof(L));
    head->data=10;
    head->next=NULL;
    second=(L*)malloc(sizeof(L));
    second->data=20;
    second->next=NULL;
    third=(L*)malloc(sizeof(L));
    third->data=30;
    third->next=NULL;
    head=insertend(head,40);
    L *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}