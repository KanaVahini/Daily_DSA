#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();

        for (int i = 0; i < n / 2; i++) {
            char temp = s[n - i - 1];
            s[n - i - 1] = s[i];
            s[i] = temp;
        }
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    vector<char> s(n);

    cout << "Enter the characters:\n";
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    obj.reverseString(s);

    cout << "Reversed String: ";
    for (char ch : s) {
        cout << ch;
    }
    cout << endl;

    return 0;
}