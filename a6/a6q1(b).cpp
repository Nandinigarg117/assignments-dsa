//doubly linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;


void insertBeginning(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}


void insertEnd(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}


void insertAfter(int num, int data) {
    Node* temp = head;
    while (temp && temp->data != num)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Node not found!\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
}


void deleteNode(int num) {
    Node* temp = head;

    while (temp && temp->data != num)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Node not found!\n";
        return;
    }

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next)
        temp->next->prev = temp->prev;

    delete temp;
}


void search(int num) {
    Node* temp = head;
    while (temp) {
        if (temp->data == num) {
            cout << "Node " << num << " found!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Node " << num << " not found!\n";
}


void display() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    int choice, data, num;

    do {
        cout << "\nDoubly Linked List Menu:\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After\n";
        cout << "4. Delete Node\n5. Search\n6. Display\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            insertBeginning(data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            insertEnd(data);
            break;
        case 3:
            cout << "Enter node value after which to insert: ";
            cin >> num;
            cout << "Enter new data: ";
            cin >> data;
            insertAfter(num, data);
            break;
        case 4:
            cout << "Enter node value to delete: ";
            cin >> num;
            deleteNode(num);
            break;
        case 5:
            cout << "Enter node value to search: ";
            cin >> num;
            search(num);
            break;
        case 6:
            display();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}

