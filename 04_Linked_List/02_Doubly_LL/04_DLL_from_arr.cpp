#include<iostream>
#include<vector>
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

Node* DLL_from_arr(vector<int> &arr){

  Node* head = new Node(arr[0]);
  Node* curr = head;

  for(int i=1; i<arr.size(); i++) {
    Node* newNode = new Node(arr[i]);

    curr->next = newNode;
    newNode->prev = curr;

    curr = newNode;
  }

  return head;
}

Node* printLL(Node* head) {
  Node* temp = head;

  cout << "NULL<->";
  while(temp != nullptr) {
    cout << temp-> data << "<->";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

int main() {

  vector<int> arr = {10,20,30};

  Node* head = DLL_from_arr(arr);

  printLL(head);

}