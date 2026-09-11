#include<iostream>
using namespace std;

class Node{
public :
    int data;
    Node* next;
    
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* insert_at_begin(Node* head, int newData) {
    Node * newNode = new Node(newData, head);
    return newNode;
}

void printLL(Node* head) {
    Node* temp = head;

    while(temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {

    Node* head = new Node(2);
    head->next = new Node(3);

    cout << "Before : "<<endl;

    printLL(head);

    head = insert_at_begin(head, 1);

    cout << "After"<< endl;

    printLL(head);

    return 0;
}