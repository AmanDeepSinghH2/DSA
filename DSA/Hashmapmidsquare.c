#include <stdio.h>
#include <stdlib.h>

#define size 100;

typedef struct node {
    int key;
    int data;
    struct node *next;
}H;

H *hash_table[size];

int midsquare(int key) {
    int square = key * key;
    int num_digits = floor(log10(square)) + 1;
    int extract_digits = (int)pow(10, (num_digits - 2) / 2);
    return (square / extract_digits) % 100;
}

void insert(int key, int data) {
    int index = midsquare(key);
    H *temp = (H *)malloc(sizeof(H));
    temp->key = key;
    temp->data = data;
    temp->next = NULL;
    if (hash_table[index] == NULL) {
        hash_table[index] = temp;
    } else {
        H *ptr = hash_table[index];
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

int search(int key) {
    int index = midsquare(key);
    H *ptr = hash_table[index];
    while (ptr != NULL) {
        if (ptr->key == key) {
            return ptr->data;
        }
        ptr = ptr->next;
    }
    return -1;
}

void display() {
    for (int i = 0; i < size; i++) {
        H *ptr = hash_table[i];
        printf("Index %d: ", i);
        while (ptr != NULL) {
            printf("%d %d ", ptr->key, ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    
}