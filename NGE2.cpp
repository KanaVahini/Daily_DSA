#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &arr) {

        int n = arr.size();

        // Stores the answer for every index
        vector<int> nge(n);

        // Monotonic decreasing stack
        stack<int> st;

        // Traverse twice from right to left
        // to simulate a circular array
        for (int i = 2 * n - 1; i >= 0; i--) {

            // Remove all elements smaller than or equal to current element
            // because they can never be the Next Greater Element
            while (!st.empty() && st.top() <= arr[i % n]) {
                st.pop();
            }

            // Fill answer only during the second traversal
            // (when i is within the original array)
            if (i < n) {
                if (st.empty())
                    nge[i] = -1;
                else
                    nge[i] = st.top();
            }

            // Push current element for future comparisons
            st.push(arr[i % n]);
        }

        return nge;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    vector<int> ans = obj.nextGreaterElements(arr);

    cout << "Next Greater Elements (Circular Array): ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}