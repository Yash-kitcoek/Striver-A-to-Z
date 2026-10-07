#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* removeNthFromEnd(ListNode* head, int n) {

    // Step 1: Count total number of nodes
    int count = 0;
    ListNode* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    // Step 2: If head itself needs to be deleted
    if (count == n) {

        ListNode* deleteNode = head;

        head = head->next;

        delete deleteNode;

        return head;
    }

    // Step 3: Reach the node before the node to delete
    temp = head;

    for (int i = 1; i < count - n; i++) {
        temp = temp->next;
    }

    // Step 4: Store the node that needs to be deleted
    ListNode* deleteNode = temp->next;

    // Step 5: Connect previous node to next node
    temp->next = deleteNode->next;

    // Step 6: Delete the node
    delete deleteNode;

    return head;
}

// Function to print linked list
void printList(ListNode* head) {

    ListNode* temp = head;

    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {

    // Create linked list
    ListNode* head = new ListNode(1);

    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Before deletion: ";
    printList(head);

    // Delete 2nd node from the end
    int n = 2;

    head = removeNthFromEnd(head, n);

    cout << "After deletion: ";
    printList(head);

    return 0;
}