#include <iostream>
using namespace std;

class MyLinkedList {
    struct Node {
        int val;
        Node* next;

        Node(int x) {
            val = x;
            next = nullptr;
        }
    };

    Node* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int getEle(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        Node* temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void addAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            Node* temp = head;

            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }

            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        }

        size--;
    }

    void printLL() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->val << "->";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    MyLinkedList list;

    list.addAtHead(10);
    list.addAtEnd(20);
    list.addAtEnd(30);

    cout << "Linked List: ";
    list.printLL();

    list.addAtIndex(1, 15);
    cout << "After insertion: ";
    list.printLL();

    cout << "Value at index 2: " << list.getEle(2) << endl;

    list.deleteAtIndex(1);
    cout << "After deletion: ";
    list.printLL();

    return 0;
}