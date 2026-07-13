#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp;
        vector<int> ans;
        map<int, int> mp;
        int rank = 1;

        temp.assign(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());

        for (int i = 0; i < temp.size(); i++) {
            if (mp.find(temp[i]) == mp.end()) {
                mp[temp[i]] = rank++;
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            ans.push_back(mp[arr[i]]);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = obj.arrayRankTransform(arr);

    cout << "Rank Transformed Array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}