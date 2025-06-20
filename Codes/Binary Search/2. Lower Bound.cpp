// we have to return the index of the element which is greater than equal to the target
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        
        // BRUTE FORCE APPROACH - LINEAR SEARCH
        // for (int i = 0 ; i<n ; i++){
        //     if (arr[i] == target){
        //         return i;
        //     }
        //     else if (arr[i] > target){
        //         return i;
        //     }
            
        // }
        // return n;

        // OPTIMAL - Binary Search
        int ans = n;
        int low = 0, high = n-1;
        while (low<=high){
            int mid = low + (high - low)/2;
            if (arr[mid] >= target) {
                ans = mid;
                high = mid - 1;
                
            }
            else
            {
                low = mid + 1;
                
            }
        }
        return ans;
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;

    }
    return 0;
}