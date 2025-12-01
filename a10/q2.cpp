#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A[] = {1, 2, 3, 4};
    int B[] = {3, 4, 5, 6};
    int n1 = 4, n2 = 4;

    sort(A, A + n1);
    sort(B, B + n2);

    int i = 0, j = 0;

    cout << "Common elements: ";
    while(i < n1 && j < n2) {
        if(A[i] == B[j]) {
            cout << A[i] << " ";
            i++;
            j++;
        }
        else if(A[i] < B[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    return 0;
}
