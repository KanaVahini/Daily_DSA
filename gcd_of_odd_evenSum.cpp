#include <iostream>
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;

        for (int i = 1; i <= n; i++) {
            sumOdd += (2 * i - 1);
            sumEven += (2 * i);
        }

        for (int i = min(sumOdd, sumEven); i >= 1; i--) {
            if (sumOdd % i == 0 && sumEven % i == 0) {
                return i;
            }
        }

        return 1;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter n: ";
    cin >> n;

    int result = obj.gcdOfOddEvenSums(n);

    cout << "GCD of Odd Sum and Even Sum = " << result << endl;

    return 0;
}