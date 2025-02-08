#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

void insert(int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;

    if(start == NULL){
        start = new_node;
        start->prev = new_node;
        start->next = new_node;
    }
    else{
        new_node->next = start;
        new_node->prev = start->prev;
        start->prev->next = new_node;
        start->prev = new_node;
    }
}

void display(){
    struct node *ptr = start;
    if(start == NULL){
        printf("List is empty\n");
    }
    else{
        printf("List is:\n");
        do{
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }while(ptr != start);
    }
}

int main(){
    int choice, data;
    while(1){
        printf("1.Insert\n2.Display\n3.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
