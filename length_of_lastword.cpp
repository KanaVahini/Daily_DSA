#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int max_count = 0;

        // Remove trailing spaces
        while (!s.empty() && s.back() == ' ') {
            s.pop_back();
        }

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (isalpha(ch)) {
                count++;
            } else {
                count = 0;
                max_count = 0;
            }

            if (count > max_count) {
                max_count = count;
            }
        }

        return max_count;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    cout << "Length of last word: " << obj.lengthOfLastWord(s) << endl;

    return 0;
}