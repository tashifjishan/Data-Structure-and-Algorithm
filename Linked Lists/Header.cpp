#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Creates a dummy head node
Node* createHeader() {
    Node* header = new Node{-1, nullptr};
    return header;
}

void insert(Node* header, int value) {
    Node* newNode = new Node{value, nullptr};
    Node* current = header;
    while (current->next)
        current = current->next;
    current->next = newNode;
}

void traverse(Node* header) {
    Node* current = header->next;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

void deleteFirst(Node* header) {
    if (!header->next) return;
    Node* temp = header->next;
    header->next = temp->next;
    delete temp;
}

int main() {
    Node* header = createHeader();
    insert(header, 10);
    insert(header, 20);
    insert(header, 30);
    traverse(header);

    deleteFirst(header);
    traverse(header);

    return 0;
}
