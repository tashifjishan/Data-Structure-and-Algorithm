#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at head
void insertHead(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

// Insert at tail
void insertTail(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next)
        current = current->next;
    current->next = newNode;
}

// Insert at a given position (0-indexed)
void insertAtPosition(Node*& head, int pos, int value) {
    if (pos == 0) {
        insertHead(head, value);
        return;
    }
    Node* current = head;
    for (int i = 0; i < pos - 1 && current; i++)
        current = current->next;
    if (!current) return;
    Node* newNode = new Node{value, current->next};
    current->next = newNode;
}

// Traverse
void traverse(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Delete head
void deleteHead(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete tail
void deleteTail(Node*& head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* current = head;
    while (current->next->next)
        current = current->next;
    delete current->next;
    current->next = nullptr;
}

// Delete at position
void deleteAtPosition(Node*& head, int pos) {
    if (!head) return;
    if (pos == 0) {
        deleteHead(head);
        return;
    }
    Node* current = head;
    for (int i = 0; i < pos - 1 && current->next; i++)
        current = current->next;
    Node* temp = current->next;
    if (!temp) return;
    current->next = temp->next;
    delete temp;
}

int main() {
    Node* head = nullptr;

    insertTail(head, 10);
    insertTail(head, 20);
    insertHead(head, 5);
    insertAtPosition(head, 2, 15);
    traverse(head);

    deleteHead(head);
    deleteTail(head);
    deleteAtPosition(head, 1);
    traverse(head);

    return 0;
}
