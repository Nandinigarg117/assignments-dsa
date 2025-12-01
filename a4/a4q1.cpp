#include <iostream>
using namespace std;

class impqueue {
    int start, end, size;
    int arr[10];

public:
    impqueue() {
        start = end = -1;
        size = 0;
    }

    bool isempty() {
        return (start == -1 && end == -1);
    }

    bool isfull() {
        return (size == 10);
    }

    void enqueue(int val) {
        if (isfull()) {
            cout << "Queue is full\n";
            return;
        }
        if (isempty()) {
            start = end = 0;
        } else {
            end++;
        }
        arr[end] = val;
        size++;
        cout << val << " enqueued successfully.\n";
    }

    void dequeue() {
        if (isempty()) {
            cout << "Queue is already empty\n";
            return;
        }
        cout << arr[start] << " deleted\n";
        start++;
        size--;
        if (start > end) { 
            start = end = -1;
            size = 0;
        }
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Elements of queue: ";
        for (int i = start; i <= end; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void peek() {
        if (isempty()) {
            cout << "Queue is empty\n";
        } else {
            cout << "Front element = " << arr[start] << endl;
        }
    }
};

int main() {
    impqueue q;
    int choice, val;

    while (1) {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. isEmpty\n";
        cout << "5. isFull\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            q.enqueue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            cout << (q.isempty() ? "Queue is EMPTY\n" : "Queue is NOT empty\n");
            break;
        case 5:
            cout << (q.isfull() ? "Queue is FULL\n" : "Queue is NOT full\n");
            break;
        case 6:
            q.display();
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
