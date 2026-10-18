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

Node* odd_even(Node* head) {
  if(head == nullptr || head->next == nullptr) {
    return head;
  }

  Node* odd = head;
  Node* even = head->next;
  Node* evenHead = even;

  while(even != nullptr && even->next != nullptr) {
    odd->next = even->next;
    odd = odd->next;

    even->next = odd->next;
    even = even->next;
  }

  odd->next = evenHead;
  return head;
}

Node* printLL(Node* head) {
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

  printLL(head);

  cout << endl;

  odd_even(head);
  cout << "After odd even sorting : " << endl;

  printLL(head);
;
  return 0;
}