#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void traverse(Node* head) {
    if (!head) return;
    Node* current = head;
    do {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != head);
    cout << "(head)\n";
}

void deleteHead(Node*& head) {
    if (!head) return;
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node* last = head;
    while (last->next != head)
        last = last->next;

    Node* temp = head;
    head = head->next;
    last->next = head;
    delete temp;
}

void deleteTail(Node*& head) {
    if (!head) return;
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    while (current->next->next != head)
        current = current->next;

    delete current->next;
    current->next = head;
}

int main() {
    Node* head = nullptr;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    traverse(head);

    deleteHead(head);
    deleteTail(head);
    traverse(head);

    return 0;
}
