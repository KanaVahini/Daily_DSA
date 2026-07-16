#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int low = 0;
        int high = nums.size() - 1;

        // Find first occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans[0] = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        // Find last occurrence
        low = 0;
        high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans[1] = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target element: ";
    cin >> target;

    Solution obj;
    vector<int> result = obj.searchRange(nums, target);

    cout << "First Position: " << result[0] << endl;
    cout << "Last Position: " << result[1] << endl;

    return 0;
}