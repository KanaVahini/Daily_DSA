#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        string ans = "";

        for (int i = 0; i < strs[0].length(); i++) {
            char ch = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {

                // Check if current string is shorter
                // or characters don't match
                if (i >= strs[j].length() || strs[j][i] != ch) {
                    return ans;
                }
            }

            ans.push_back(ch);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);

    cout << "Enter the strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    cout << "Longest Common Prefix: "
         << obj.longestCommonPrefix(strs) << endl;

    return 0;
}