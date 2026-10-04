#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

void delete_at_tail(Node*& head) {

    if(head == nullptr) {
        return;
    }

    // Only one node
    if(head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    // Go to last node
    while(temp->next != nullptr) {
        temp = temp->next;
    }

    // Disconnect last node
    temp->prev->next = nullptr;

    // Delete last node
    delete temp;
}

void printLL(Node* head) {
    Node* temp = head;

    while(temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL";
}

int main() {

    Node* head = new Node(10);

    head->next = new Node(20);
    head->next->prev = head;

    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    delete_at_tail(head);

    printLL(head);
}