#include <iostream>
#include <vector>

using namespace std;

// Structure of doubly linked list Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

// Seedha function bina class ke
vector<vector<int>> displayList(Node *head) {
    vector<vector<int>> result;
    
    vector<int> forwardList;
    vector<int> backwardList;
    
    if (head == nullptr) {
        return result;
    }
    
    Node* temp = head;
    Node* tail = nullptr;
    
    // Forward Traversal
    while (temp != nullptr) {
        forwardList.push_back(temp->data);
        tail = temp; 
        temp = temp->next;
    }
    
    // Backward Traversal
    temp = tail;
    while (temp != nullptr) {
        backwardList.push_back(temp->data);
        temp = temp->prev;
    }
    
    result.push_back(forwardList);
    result.push_back(backwardList);
    
    return result;
}

int main() {
    // Test case: 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    // Function call bina kisi object ke
    vector<vector<int>> output = displayList(head);

    // Output print karna
    cout << "[\n";
    for (const auto& row : output) {
        cout << "  [ ";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "]\n";
    }
    cout << "]\n";

    return 0;
}