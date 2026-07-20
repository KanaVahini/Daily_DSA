#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = s.length() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count the last word
        while (i >= 0 && isalpha(s[i])) {
            count++;
            i--;
        }

        return count;
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    cout << "Length of last word: " << obj.lengthOfLastWord(s) << endl;

    return 0;
}