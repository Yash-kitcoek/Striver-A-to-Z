#include<iostream>
using namespace std;

class Node {
public :
  int data;
  Node* next;
  Node* prev;

  Node(int val) {
    data = val;
    next = nullptr;
    prev = nullptr;
  }
};

Node* reverse_LL(Node* head) {
  
  Node* prev = nullptr;
  Node* curr = head;

  while(curr != nullptr) {
    Node* nextNode = curr->next;
    curr->next = prev;

    prev = curr;
    curr = nextNode;
  }

  return prev;

}

Node* printLL(Node* head) {
  Node* curr = head;

  while(curr != nullptr) {
    cout << curr->data << "->";

    curr = curr->next;
  }
  cout <<"NULL";
}

int main() {
 Node* head = new Node(10);
 head -> next = new Node(20);
 head -> next -> next = new Node(30);

 cout << "Before Reversing :" << endl;

 printLL(head);

 head = reverse_LL(head);
 cout << endl;

 cout << "After Reversing : "<< endl;

 printLL(head);
}