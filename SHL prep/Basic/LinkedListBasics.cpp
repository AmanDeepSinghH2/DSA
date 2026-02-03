#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() { head = nullptr; }

    void insertAtHead(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTail(30);
    list.insertAtTail(40);
    
    cout << "Linked List: "; list.printList();
    
    cout << "Deleting 30..." << endl;
    list.deleteNode(30);
    
    cout << "Linked List: "; list.printList();

    return 0;
}
