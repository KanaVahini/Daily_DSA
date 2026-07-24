#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {

        // Using vector as a stack
        vector<int> st;

        // Traverse each asteroid
        for (int asteroid : asteroids) {

            // Positive asteroid moves right
            // It cannot collide immediately, so push it
            if (asteroid > 0) {
                st.push_back(asteroid);
            }
            else {

                // Destroy all smaller positive asteroids
                while (!st.empty() &&
                       st.back() > 0 &&
                       st.back() < abs(asteroid)) {

                    st.pop_back();
                }

                // If both asteroids are of equal size,
                // both get destroyed
                if (!st.empty() && st.back() == abs(asteroid)) {
                    st.pop_back();
                }

                // If stack is empty or top is negative,
                // current asteroid survives
                else if (st.empty() || st.back() < 0) {
                    st.push_back(asteroid);
                }

                // Else:
                // Top is a larger positive asteroid,
                // so current negative asteroid is destroyed.
                // Do nothing.
            }
        }

        return st;
    }
};

int main() {

    int n;

    cout << "Enter number of asteroids: ";
    cin >> n;

    vector<int> asteroids(n);

    cout << "Enter asteroid values: ";
    for (int i = 0; i < n; i++) {
        cin >> asteroids[i];
    }

    Solution obj;

    vector<int> ans = obj.asteroidCollision(asteroids);

    cout << "Remaining asteroids: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}