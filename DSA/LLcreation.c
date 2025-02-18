#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}L;
int main()
{
    L *head ;
    L *second;
    head=(L*)malloc(sizeof(L));
    second=(L*)malloc(sizeof(L));
    head->data=10;
    head->next=second;
    second->data=20;
    second->next=NULL;
    L *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}
