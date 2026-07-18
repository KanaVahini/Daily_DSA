#include <iostream>
#include <vector>
#include <algorithm>   // for __gcd
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = nums[0];
        int largest = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < smallest)
                smallest = nums[i];

            if (nums[i] > largest)
                largest = nums[i];
        }

        return __gcd(smallest, largest);
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
    cout << "GCD of smallest and largest element = "
         << obj.findGCD(nums) << endl;

    return 0;
}