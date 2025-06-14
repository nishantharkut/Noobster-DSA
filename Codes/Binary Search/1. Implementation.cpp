#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int BS (vector<int>& arr,int low, int high, int target){
        if (low<=high){
            int mid = low + (high - low)/2;
            if (arr[mid] == target) return mid;
            else if (arr[mid]< target){
                return BS(arr, mid+1, high, target);
                
            }
            else{
                return BS(arr, low, mid-1, target);
            }
        }
        return -1;
    }
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        return BS(arr, 0, n-1, target);

    }
};

int main() {
    Solution ob;

    // Test Case 1
    vector<int> arr1 = {1, 3, 5, 7, 9};
    int target1 = 7;
    cout << "Test 1: " << ob.search(arr1, target1) << endl; // Expected: 3

    // Test Case 2
    vector<int> arr2 = {2, 4, 6, 8};
    int target2 = 5;
    cout << "Test 2: " << ob.search(arr2, target2) << endl; // Expected: -1

    // Test Case 3
    vector<int> arr3 = {0, 10, 20, 30, 40, 50};
    int target3 = 0;
    cout << "Test 3: " << ob.search(arr3, target3) << endl; // Expected: 0

    // Test Case 4
    vector<int> arr4 = {1};
    int target4 = 1;
    cout << "Test 4: " << ob.search(arr4, target4) << endl; // Expected: 0

    // Test Case 5
    vector<int> arr5 = {1, 2, 3, 4, 5};
    int target5 = 10;
    cout << "Test 5: " << ob.search(arr5, target5) << endl; // Expected: -1

    return 0;
}