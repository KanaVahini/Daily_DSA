#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;

        // Count the number of 0s, 1s, and 2s
        for (int x : nums) {
            if (x == 0)
                zero++;
            else if (x == 1)
                one++;
            else
                two++;
        }

        // Overwrite the array
        int i = 0;

        while (zero--)
            nums[i++] = 0;

        while (one--)
            nums[i++] = 1;

        while (two--)
            nums[i++] = 2;
    }
};

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements (only 0, 1, and 2): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    obj.sortColors(nums);

    cout << "Sorted array: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}