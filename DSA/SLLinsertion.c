#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}L;

L *insert(L *head,int data)
{
    L *new=(L*)malloc(sizeof(L));
    new->data=data;
    new->next=head;
    if(head!=NULL)
    {
        head->prev=new;
    }
    head=new;
}
int main()
{
    L *head=NULL;
    L *second=(L*)malloc(sizeof(L));
    L *third=(L*)malloc(sizeof(L));
    head=(L*)malloc(sizeof(L));
    head->data=10;
    head->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=NULL;
    head=insert(head,40);
    L *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}