#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int nums[] = {2, 3, 2, 4, 3, 2};
    int n = 6;

    sort(nums, nums + n);

    cout << "Frequencies:\n";

    int count = 1;
    for(int i = 1; i < n; i++) {
        if(nums[i] == nums[i - 1]) {
            count++;
        } else {
            cout << nums[i - 1] << " → " << count << " times\n";
            count = 1;
        }
    }

    // Print last element frequency
    cout << nums[n - 1] << " → " << count << " times\n";

    return 0;
}
