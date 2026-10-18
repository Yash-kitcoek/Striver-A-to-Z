#include<iostream>
using namespace std;

class Node {
 public :
  int data;
  Node* prev;
  Node* next;
  
  Node(int val) {
    data = val;
    prev = next = nullptr;
  }
};

Node* Deletemiddle_LL(Node* head) {
  if(head == nullptr || head->next == nullptr) {
    return nullptr;
  }

  Node* slow = head;
  Node* prev = slow;
  Node* fast = head;

  while(fast != nullptr && fast->next != nullptr) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  prev->next = slow->next;;
  delete slow;

  return head;
}


void printLL(Node* head) {
  while(head != nullptr) {
    cout << head->data <<"->";
    head = head->next;
  }
  cout << "NULL";
}


int main() {

  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);


  cout << "Original LL " << endl;
  printLL(head);

  cout << endl;

  Deletemiddle_LL(head);

  printLL(head);

  return 0;
}