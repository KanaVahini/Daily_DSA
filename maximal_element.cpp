#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to print an array
void printArray(vector<int> &arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

// Function to find maximum element
int findMax(vector<int> &arr)
{
    int maxi = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > maxi)
            maxi = arr[i];
    }

    return maxi;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Array: ";
    printArray(arr);

    cout << "Maximum element = " << findMax(arr) << endl;

    return 0;
}