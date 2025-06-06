#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {

   public:
    int LargestElementIdx(vector<int> arr){
        int n = arr.size();
        int maxIdx = 0;
        for (int i = 0; i<n;i++){
            
            if (arr[i] < arr[i+1]) maxIdx = i +1;
            else{ continue;} 
        }
        return maxIdx;
    }
    int LargestElement(vector<int> arr){
        int n = arr.size();
        int maxIdx = 0;
        for (int i = 0; i<n;i++){
            if (arr[i] < arr[i+1]) maxIdx = i +1; 
            else{continue;} 
        }
        
        return arr[maxIdx];
    }
  };

int main() {
    Solution sol;

    // --- Test Case 1: Strictly increasing ---
    {
        vector<int> arr = {1, 2, 3, 4, 5};
        // Expected index: 4    (element 5)
        // Expected value: 5
        cout << "TC1 idx = " << sol.LargestElementIdx(arr)
             << "   val = " << sol.LargestElement(arr) << "\n";
    }

    // --- Test Case 2: Strictly decreasing ---
    {
        vector<int> arr = {5, 4, 3, 2, 1};
        // Expected index: 0    (element 5)
        // Expected value: 5
        cout << "TC2 idx = " << sol.LargestElementIdx(arr)
             << "   val = " << sol.LargestElement(arr) << "\n";
    }

    // --- Test Case 3: Peak in the middle ---
    {
        vector<int> arr = {3, 5, 2, 5, 1};
        // Walk through pairs:
        //   3<5  → idx becomes 1
        //   5<2  → no change
        //   2<5  → idx becomes 3
        //   5<1  → no change
        // Final idx: 3  (element 5)
        // Final value: 5
        cout << "TC3 idx = " << sol.LargestElementIdx(arr)
             << "   val = " << sol.LargestElement(arr) << "\n";
    }

    // --- Test Case 4: All elements equal ---
    {
        vector<int> arr = {7, 7, 7, 7};
        // Since arr[i] < arr[i+1] is never true, maxIdx stays 0
        // Expected index: 0   (element 7)
        // Expected value: 7
        cout << "TC4 idx = " << sol.LargestElementIdx(arr)
             << "   val = " << sol.LargestElement(arr) << "\n";
    }

    // --- Test Case 5: Two‐element arrays ---
    {
        vector<int> a1 = {10, 20};
        // 10 < 20 → idx = 1   value = 20
        cout << "TC5a idx = " << sol.LargestElementIdx(a1)
             << "   val = " << sol.LargestElement(a1) << "\n";

        vector<int> a2 = {20, 10};
        // 20 < 10 → never true → idx = 0  value = 20
        cout << "TC5b idx = " << sol.LargestElementIdx(a2)
             << "   val = " << sol.LargestElement(a2) << "\n";
    }

    // --- Test Case 6: Negative numbers ---
    {
        vector<int> arr1 = {-1, -2, -3};
        // -1 < -2? no → idx stays 0 → value = -1
        cout << "TC6a idx = " << sol.LargestElementIdx(arr1)
             << "   val = " << sol.LargestElement(arr1) << "\n";

        vector<int> arr2 = {-3, -2, -1};
        // -3 < -2 → idx = 1
        // -2 < -1 → idx = 2
        // Final idx = 2  value = -1
        cout << "TC6b idx = " << sol.LargestElementIdx(arr2)
             << "   val = " << sol.LargestElement(arr2) << "\n";
    }

    // --- Test Case 7: Single‐peak plateau ---
    {
        vector<int> arr = {1, 3, 3, 2};
        // 1<3 → idx=1
        // 3<3 → false
        // 3<2 → false
        // Final idx=1 (element at index 1 is 3)
        cout << "TC7 idx = " << sol.LargestElementIdx(arr)
             << "   val = " << sol.LargestElement(arr) << "\n";
    }

    // --- Test Case 8: Zigzag pattern ---
    {
        vector<int> arr = {2, 5, 1, 4, 3};
        // 2<5 → idx=1
        // 5<1 → no
        // 1<4 → idx=3
        // 4<3 → no
        // Final idx=3 (element 4), value=4
        cout << "TC8 idx = " << sol.LargestElementIdx(arr)
             << "   val = " << sol.LargestElement(arr) << "\n";
    }

    // --- Test Case 9: Large identical prefix, then increase at end ---
    {
        vector<int> arr(1000, 42);
        arr.push_back(100);
        // All initial pairs 42<42 → false
        // At i=999: 42<100 → idx=1000
        // Expected idx=1000, value=100
        cout << "TC9 idx = " << sol.LargestElementIdx(arr)
             << "   val = " << sol.LargestElement(arr) << "\n";
    }

    return 0;
}