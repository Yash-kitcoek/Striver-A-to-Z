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

Node* middle_LL(Node* head) {
  Node* slow = head;
  Node* fast = head;

  while(fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
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

 Node* mid = middle_LL(head);

 cout << "Middle Node : " << mid->data << endl;
 
  return 0;
}