#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    int data;
    struct nodde *next;
    struct node *prev;
}a;

void insertAtStart(a **head,int data)
{
    a *newnode=(a*)malloc(sizeof(a));
    newnode->data=data;
    if(*head==NULL)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        *head=newnode;
    }
    else
    {
        newnode->next=*head;
        newnode->prev=NULL;
        (*head)->prev=newnode;
        *head=newnode;
    }
}
 int main()
 {
     a *head=NULL;
     a *second,*third;
     head=(a*)malloc(sizeof(a));
     second=(a*)malloc(sizeof(a));
     third=(a*)malloc(sizeof(a));
     head->data=10;
     head->next=second;
     head->prev=NULL;
     second->data=20;
     second->next=third;
     second->prev=head;
     third->data=30;
     third->next=NULL;
     third->prev=second;
     insertAtStart(&head,40);
     a *temp=head;
     while(temp!=NULL)
     {
         printf("%d ",temp->data);
         temp=temp->next;
     }
     return 0;
 }