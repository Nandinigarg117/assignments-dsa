#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;


void insertEnd(int data) {
    Node* newNode = new Node();
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head; 
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}


int getSize() {
    if (head == NULL) return 0;

    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}


void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}


int main() {
    int n, data;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> data;
        insertEnd(data);
    }

    cout << "\nCircular Linked List: ";
    display();

    cout << "Size of Circular Linked List = " << getSize() << endl;
    return 0;
}
