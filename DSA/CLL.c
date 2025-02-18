#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

void insert(struct node **head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if(*head == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head = new_node;
    }
    else
    {
        new_node->next = (*head)->next;
        new_node->prev = *head;
        (*head)->next->prev = new_node;
        (*head)->next = new_node;
        *head = new_node;
    }
}

void display(struct node *head)
{
    struct node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
}

int main()
{
    struct node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    display(head);
    return 0;
}
