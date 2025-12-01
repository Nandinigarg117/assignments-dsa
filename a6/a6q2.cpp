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


void display() {
    if (head == NULL) {
        cout << "List is empty";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data; 
    cout << endl;
}


int main() {
    insertEnd(20);
    insertEnd(100);
    insertEnd(40);
    insertEnd(80);
    insertEnd(60);

    cout << "Circular Linked List: ";
    display();

    return 0;
}



