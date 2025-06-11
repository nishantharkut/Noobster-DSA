#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {

    public:
    bool isArrSorted(vector<int> arr)   //write function here 
        {  
            // The array is said to be sorted if every elemnt is in ascending order.
            // incorrect loop condition in first attempt, make sure you dry run before submitting
            // -----------INCORRECT CODE--------------
            // 1. out of bounds index  2. incorrect return in for loop
            /*
            for (int i = 0; i<n; i++){
                if (arr[i]>arr[i+1]) return false;
                return true;
            }
            */

            int n = arr.size();

            for (int i = 0; i<n-1; i++){
                if (arr[i]>arr[i+1]) return false;
            }   
            return true;
        }
  };

int main() {
    Solution obs;

    vector<vector<int>> testCases = {
        {1, 2, 3, 4, 5},          // Sorted
        {1, 2, 2, 3, 4},          // Sorted with duplicates
        {5, 4, 3, 2, 1},          // Reverse sorted
        {1},                     // Single element
        {},                      // Empty array
        {10, 20, 15, 30, 40},    // Unsorted
        {2, 2, 2, 2},            // All equal elements (sorted)
        {1, 3, 2, 4, 5}          // Partially unsorted
    };

    int testNum = 1;
    for (auto& arr : testCases) {
        cout << "Test Case " << testNum++ << ": ";
        for (int x : arr) cout << x << " ";
        if (obs.isArrSorted(arr)) {
            cout << "-> Sorted\n";
        } else {
            cout << "-> Not Sorted\n";
        }
    }

    return 0;
}