#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;


void insertBeginning(int data) {
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
    head = newNode;
}


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


void insertAfter(int num, int data) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        if (temp->data == num) {
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Node " << num << " not found!\n";
}


void deleteNode(int num) {
    if (head == NULL) return;

    Node* curr = head;
    Node* prev = NULL;

    if (head->data == num && head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    while (curr->next != head && curr->data != num) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->data == num) {
        if (curr == head) {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            head = head->next;
            temp->next = head;
        } else {
            prev->next = curr->next;
        }
        delete curr;
    } else {
        cout << "Node not found!\n";
    }
}

void search(int num) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    bool found = false;

    do {
        if (temp->data == num) {
            found = true;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (found)
        cout << "Node " << num << " found!\n";
    else
        cout << "Node " << num << " not found!\n";
}


void display() {
    if (head == NULL) {
        cout << "List empty\n";
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
    int choice, data, num;

    do {
        cout << "\nCircular Linked List Menu:\n";
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
