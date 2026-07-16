#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        else if (arr[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n, key;

    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int index = binarySearch(arr, n, key);

    if (index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found";

    return 0;
}

/*Binary Search using recursion

class Solution{
private:
    int func(vector<int>&nums, int low, int high, int target){
        if(low>high){
            return -1;
        }
        int ind;
        int mid = (low+high)/2;
        if(nums[mid] == target){
            ind = mid;
        }
        else if(nums[mid]<target){
            ind = func(nums,mid+1,high,target);
        }
        else{
            ind = func(nums,low,mid-1,target);
        }
        return ind;
    }
public:
    int search(vector<int> &nums, int target){
        int n = nums.size();
        int res = func(nums,0,n-1,target);
        return res;
    }
};


















*/