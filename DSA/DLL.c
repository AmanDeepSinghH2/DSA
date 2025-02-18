typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *head = NULL;

Node* createNode(int data) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insertAtStart(int data) {
    Node *newnode = createNode(data);
    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insertAtEnd(int data) {
    Node *newnode = createNode(data);
    if (head == NULL) {
        head = newnode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void insertAtPos(int data, int pos) {
    Node *newnode = createNode(data);
    if (pos == 1) {
        insertAtStart(data);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    newnode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void deleteAtStart() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    Node *last = temp->next;
    temp->next = NULL;
    free(last);
}

void deleteAtPos(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        deleteAtStart();
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = temp;
    }
    free(nodeToDelete);
}

void display() {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertAtStart(10);
    insertAtStart(20);
    insertAtStart(30);
    display();
    insertAtEnd(40);
    insertAtEnd(50);
    display();
    insertAtPos(25, 3);
    display();
    deleteAtStart();
    display();
    deleteAtEnd();
    display();
    deleteAtPos(2);
    display();

    return 0;
}

