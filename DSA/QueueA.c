#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = 0, rear = -1;

int isFull() {
    return (rear + 1) % MAX == front;
}

int isEmpty() {
    return front == rear + 1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot insert %d\n", value);
    } else {
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("%d inserted into the queue\n", value);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Nothing to delete.\n");
    } else {
        printf("%d deleted from the queue\n", queue[front]);
        front = (front + 1) % MAX;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[i]);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    dequeue();
    dequeue();
    display();
    enqueue(60);
    display();
    return 0;
}

