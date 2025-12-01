#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int>& q) {
    int s = q.size();
    queue<int> q1, q2;

    // split into two halves
    for (int i = 0; i < s; i++) {
        if (i < s / 2) {
            q1.push(q.front());
        } else {
            q2.push(q.front());
        }
        q.pop();
    }

    // merge back interleaving
    while (!q1.empty() || !q2.empty()) {
        if (!q1.empty()) {
            q.push(q1.front());
            q1.pop();
        }
        if (!q2.empty()) {
            q.push(q2.front());
            q2.pop();
        }
    }
}

int main() {
    queue<int> q;
    cout << "Enter number of elements: ";
    int n, ele;
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> ele;
        q.push(ele);
    }

    interleave(q);

    cout << "Interleaved queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
