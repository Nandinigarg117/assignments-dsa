#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};


void storeValues(Node* root, int arr[], int &idx) {
    if (root == NULL) return;

    arr[idx++] = root->data;
    storeValues(root->left, arr, idx);
    storeValues(root->right, arr, idx);
}

bool hasDuplicate(Node* root) {
    if (root == NULL) return false;

    int arr[1000];     
    int n = 0;

    storeValues(root, arr, n);

    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true;  // duplicate found
            }
        }
    }

    return false; 
}

int main() {
   
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(2); // duplicate

    if (hasDuplicate(root))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";

    return 0;
}
