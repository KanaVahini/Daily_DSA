#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        // Push all elements into the max heap
        for (int num : nums) {
            pq.push(num);
        }

        // Remove the largest k-1 elements
        while (k > 1) {
            pq.pop();
            k--;
        }

        // The top is now the kth largest
        return pq.top();
    }
};

int main() {
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    int ans = obj.findKthLargest(nums, k);

    cout << "The " << k << "th largest element is: " << ans << endl;

    return 0;
}