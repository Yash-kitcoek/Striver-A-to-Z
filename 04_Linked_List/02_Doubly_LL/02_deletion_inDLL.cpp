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

Node* delLL(Node* head, int k) {
  if(head == nullptr) return nullptr;

  Node* temp = head;

  if(k == 1) {
    head = head->next;

    if(head != nullptr) {
      head->prev = nullptr;
    }

    delete temp;
    return head;
  }

  for(int i=1; temp != nullptr && i < k; i++) {
    temp = temp->next;
  }

  if(temp == nullptr) {
    return head;
  }

  if(temp -> next != nullptr) {
    temp->next->prev = temp->prev; 
  }

  if(temp -> prev != nullptr){
    temp->prev->next = temp->next;
  }

  delete temp;
  return head;
}

void printLL(Node* head) {
  Node* temp = head;

  while(temp != nullptr) {
    cout << temp-> data << "<->";
    temp = temp->next;
  }
  cout << "nullptr";
}

int main() {
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->prev = head;
  head->next->next = new Node(3);
  head->next->next->prev = head->next;

  cout << "List Before Deletion : " << endl;
  printLL(head);
  cout << endl;
 
  cout << "After Deletion : "<< endl;
  head = delLL(head, 2);
  printLL(head);

  return 0;
}