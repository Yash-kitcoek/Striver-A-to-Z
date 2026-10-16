
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

Node* add2LL(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* curr = dummy;
    int carry = 0;

    while(l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;

        if(l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }

        if(l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;

        curr->next = new Node(digit);
        curr = curr->next;
    }

    Node* result = dummy->next;
    delete dummy;

    return result;
}

// Function to print linked list
void printLL(Node* head) {
    while(head != nullptr) {
        cout << head->data;
        
        if(head->next != nullptr) {
            cout << " -> ";
        }

        head = head->next;
    }
    cout << endl;
}

int main() {
    // First number: 342 (reverse order)
    Node* l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3);

    // Second number: 465 (reverse order)
    Node* l2 = new Node(5);
    l2->next = new Node(6);
    l2->next->next = new Node(4);

    cout << "First Linked List: ";
    printLL(l1);

    cout << "Second Linked List: ";
    printLL(l2);

    Node* result = add2LL(l1, l2);

    cout << "Sum: ";
    printLL(result);

    return 0;
}
