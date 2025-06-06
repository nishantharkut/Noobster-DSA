#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {

    public:
    void printArray(const vector<int>& arr) {
        for (int val : arr) {
            cout << val << " ";
        }
        cout << "\n";
    }

    void InsertionSort(vector<int> &arr)      //write function here 
        {  
            // Your code goes here   
            int n = arr.size();
            for (int i = 0; i<=n-1; i++){
                int j = i;
                while (j>0 && arr[j-1] >arr[j]){
                    swap(arr[j-1], arr[j]);
                    j--;
                }
            }
        }
  };

int main() {
    Solution ob;
    vector<vector<int>> testCases = {
        {2, 23, 27, 132, 1, 5},    // mixed order
        {1, 2, 3, 4, 5},           // already sorted
        {5, 4, 3, 2, 1},           // reverse sorted
        {1},                       // single element
        {},                        // empty array
        {5, 5, 5, 5},              // all same elements
        {10, -1, 3, 0, -5},        // includes negative numbers
        {INT_MAX, INT_MIN, 0},     // boundary values
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i+1 << " before sorting: ";
        ob.printArray(testCases[i]);
        ob.InsertionSort(testCases[i]);
        cout << "Test case " << i+1 << " after sorting:  ";
        ob.printArray(testCases[i]);
        cout << "--------------------------\n";
    }

    return 0;
}