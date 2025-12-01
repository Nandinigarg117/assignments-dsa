
#include <iostream>
#include <vector>
using namespace std;

class MaxPriorityQueue {
    vector<int> heap;

    void heapifyDown(int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;

        while (i > 0 && heap[i] > heap[parent]) {
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

    int getMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty\n";
            return -1;
        }
        return heap[0];
    }

    void deleteMax() {
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
    MaxPriorityQueue pq;

    pq.insert(10);
    pq.insert(40);
    pq.insert(20);
    pq.insert(5);

    cout << "Max Element: " << pq.getMax() << endl;

    pq.deleteMax();

    cout << "After deleting max: ";
    pq.display();
}
