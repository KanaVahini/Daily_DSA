#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    vector<int> computeLPS(string &pat) {
        int m = pat.length();

        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    vector<int> search(string &pat, string &txt) {

        int n = txt.length();
        int m = pat.length();

        vector<int> lps = computeLPS(pat);

        vector<int> ans;

        int i = 0;
        int j = 0;

        while (i < n) {

            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == m) {
                ans.push_back(i - j);   // 0-based index
                j = lps[j - 1];
            }
            else if (i < n && txt[i] != pat[j]) {

                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return ans;
    }
};

int main() {
    string txt, pat;

    cout << "Enter text: ";
    cin >> txt;

    cout << "Enter pattern: ";
    cin >> pat;

    Solution obj;
    vector<int> ans = obj.search(pat, txt);

    if (ans.empty()) {
        cout << "Pattern not found" << endl;
    } else {
        cout << "Pattern found at indices: ";
        for (int index : ans) {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}