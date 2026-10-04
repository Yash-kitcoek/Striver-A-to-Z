#include<iostream>
using namespace std;

class Node {
  public:
  int data;
  Node* next;
  Node* prev;

  Node(int val){
    data = val;
    next = nullptr;
    prev = nullptr;
  }

};

Node* insertAtLL(Node* head, int p, int x){
  if(head == nullptr) {
    return head;
  }

  Node* temp = head;

  for(int i=0; i<p; i++) {
    if(temp->next == nullptr) {
      return head;
    }

    temp = temp->next;
  }

  Node* newNode = new Node(x);

  newNode->next = temp->next;
  newNode->prev = temp;

  if(temp->next != nullptr) {
    temp->next->prev = newNode;
  }

  temp->next = newNode;
  
  return head;
}

Node* printLL(Node* head) {
  Node* temp = head;

  cout << "NULL<->";
  while(temp != nullptr) {
    cout << temp-> data << "<->";
    temp = temp-> next;
  }
  cout << "NULL";
}

int main() {
  Node* head = new Node(10);
  head->next = new Node(20);
  head->next->prev = head;
  
  head->next->next = new Node(30);
  head->next->next->prev = head->next;

  insertAtLL(head, 1, 66);

  printLL(head);

}