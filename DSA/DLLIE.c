#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}a;
a *inserte(a *head,int data)
{
    a *new=(a*)malloc(sizeof(a));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    if(head==NULL)
    {
        head=new;
        return head;
    }
    else{
        a *temp=head;
        if(temp->next==NULL)
        {
            temp->next=new;
            new->prev=temp;
            return head;
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=new;
            new->prev=temp;
            return head;
        }
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
    inserte(&head,40);
    a *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}