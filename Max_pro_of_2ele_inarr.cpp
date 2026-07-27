#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxPro = INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = (nums[i] - 1) * (nums[j] - 1);
                if (product > maxPro) {
                    maxPro = product;
                }
            }
        }

        return maxPro;
    }
};

int main() {
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    cout << "Maximum Product = " << obj.maxProduct(nums) << endl;

    return 0;
}