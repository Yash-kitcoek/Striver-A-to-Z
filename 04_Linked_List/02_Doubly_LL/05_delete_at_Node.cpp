#include<iostream>
using namespace std;

class Node {
  public :
  int val;
  Node* next;
    Node(int data) {
      val = data;
      next = nullptr;
    }
};

void delete_at_Node(Node* node) {

  node->val = node->next->val;

  Node* temp = node->next;

  node->next = node->next->next; 

  delete temp;

}

Node* printLL(Node* head) {
  Node* temp = head;

  while(temp != nullptr) {
    cout << temp->val << "->";
    temp = temp->next;
  }
  cout << "NULL";
}

int main() {
  Node* head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);

  delete_at_Node(head->next);

  printLL(head);
}