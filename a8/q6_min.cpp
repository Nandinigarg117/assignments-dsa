#include <iostream>
#include <vector>
using namespace std;

class MinPriorityQueue {
    vector<int> heap;

    void heapifyDown(int i) {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;

        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;

        while (i > 0 && heap[i] < heap[parent]) {
            swap(heap[i], heap[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int getMin() {
        if (heap.empty()) {
            cout << "Priority Queue is empty\n";
            return -1;
        }
        return heap[0];
    }

    void deleteMin() {
        if (heap.empty()) {
            cout << "Priority Queue is empty\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    bool isEmpty() {
        return heap.empty();
    }

    void display() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MinPriorityQueue pq;

    pq.insert(40);
    pq.insert(10);
    pq.insert(30);
    pq.insert(5);

    cout << "Min Element: " << pq.getMin() << endl;

    pq.deleteMin();

    cout << "After deleting min: ";
    pq.display();
}
