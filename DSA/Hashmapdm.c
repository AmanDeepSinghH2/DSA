#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct node {
    int key;
    int value;
    struct node *next;
} node;

node *hash_table[SIZE];

int divisionmethod(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    int index = divisionmethod(key);
    node *temp = (node *)malloc(sizeof(node));
    temp->key = key;
    temp->value = value;
    temp->next = NULL;
    if (hash_table[index] == NULL) {
        hash_table[index] = temp;
    } else {
        node *ptr = hash_table[index];
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

int search(int key) {
    int index = divisionmethod(key);
    node *ptr = hash_table[index];
    while (ptr != NULL) {
        if (ptr->key == key) {
            return ptr->value;
        }
        ptr = ptr->next;
    }
    return -1;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        node *ptr = hash_table[i];
        printf("Index %d: ", i);
        while (ptr != NULL) {
            printf("%d %d ", ptr->key, ptr->value);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main() {
    insert(1, 100);
    insert(2, 200);
    insert(3, 300);
    display();
    printf("Value of key 1: %d\n", search(1));
    return 0;
}

