#include <iostream>
using namespace std;

void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void heapSortDecreasing(int arr[], int n) {
    // Build min heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    // Extract elements
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = 6;

    heapSortDecreasing(arr, n);

    cout << "Sorted in Decreasing Order: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
