#include<iostream>
using namespace std;

class Node {
    public :
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};


void deleteLL(Node* &head) {
    Node* temp;

    while(head != nullptr) {
        temp = head;
        head = head -> next;
        delete temp;
    }
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
    head -> next = new Node(20);
    head -> next -> next = new Node(30);

    printLL(head);

    deleteLL(head);

    cout << endl;
    printLL(head);

    return 0;
}