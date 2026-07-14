#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        for (int x : nums) {
            int count = 0;

            for (int y : nums) {
                if (x == y) {
                    count++;
                }
            }

            if (count > n / 2) {
                return x;
            }
        }

        return -1;
    }
};

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int ans = obj.majorityElement(nums);

    cout << "Majority Element: " << ans << endl;

    return 0;
}