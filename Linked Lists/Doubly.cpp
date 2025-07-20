#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertTail(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next)
        current = current->next;
    current->next = newNode;
    newNode->prev = current;
}

void traverse(Node* head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

void deleteHead(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete temp;
}

void deleteTail(Node*& head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* current = head;
    while (current->next)
        current = current->next;
    current->prev->next = nullptr;
    delete current;
}

int main() {
    Node* head = nullptr;
    insertTail(head, 10);
    insertTail(head, 20);
    insertTail(head, 30);
    traverse(head);

    deleteHead(head);
    deleteTail(head);
    traverse(head);

    return 0;
}
