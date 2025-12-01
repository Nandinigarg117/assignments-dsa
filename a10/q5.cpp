#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;            // moves 1 step
        fast = fast->next->next;      // moves 2 steps

        if (slow == fast) {           // pointers meet → loop exists
            return true;
        }
    }

    return false;   // fast reached NULL → no loop
}

int main() {
    // Creating nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    // Linking: 1 → 2 → 3 → 4
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // Create loop: 4 → points to 2
    n4->next = n2;

    if (hasCycle(n1))
        cout << "true";
    else
        cout << "false";

    return 0;
}
