#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        while (k--) {

            vector<vector<int>> temp(m, vector<int>(n));

            // Last element becomes the first element
            temp[0][0] = grid[m - 1][n - 1];

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {

                    if (i == m - 1 && j == n - 1)
                        continue;

                    if (j == n - 1)
                        temp[i + 1][0] = grid[i][j];
                    else
                        temp[i][j + 1] = grid[i][j];
                }
            }

            grid = temp;
        }

        return grid;
    }
};

int main() {
    int m, n;

    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter the matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int k;
    cout << "Enter number of shifts: ";
    cin >> k;

    Solution obj;
    vector<vector<int>> ans = obj.shiftGrid(grid, k);

    cout << "\nShifted Grid:\n";
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}