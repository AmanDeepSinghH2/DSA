#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node* next;
} node;

// Queue structure
typedef struct queue {
    node* front;
    node* rear;
} queue;

// Function to create a new node
node* newNode(int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create a new queue 
queue* createQueue() {
    queue* temp = (queue*)malloc(sizeof(queue));
    temp->front = NULL;
    temp->rear = NULL;
    return temp;
}

// Function to enqueue an element
void enqueue(queue* q, int data) {
    node* temp = newNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Function to dequeue an element
int dequeue(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->front->data;
    node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Function to check if queue is empty
int isEmpty(queue* q) {
    return q->front == NULL;
}

// Function to print the queue
void printQueue(queue* q) {
    node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printQueue(q);
    printf("%d\n", dequeue(q));
    printQueue(q);
    return 0;
}
