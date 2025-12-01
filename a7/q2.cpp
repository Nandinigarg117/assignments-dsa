#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0;          
    int right = n - 1;

    while (left < right) {

        int minIndex = left;
        int maxIndex = left;

        
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;

            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

       
        swap(arr[left], arr[minIndex]);

       
        if (maxIndex == left)
            maxIndex = minIndex;

        
        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {7, 2, 9, 4, 1, 5, 3};
    int n = 7;

    cout << "Original: ";
    printArray(arr, n);

    improvedSelectionSort(arr, n);

    cout << "Sorted:   ";
    printArray(arr, n);

    return 0;
}
