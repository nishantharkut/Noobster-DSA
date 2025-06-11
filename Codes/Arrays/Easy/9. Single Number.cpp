#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        //Optimal Approach
        int XorElement = 0;
        for (int i = 0; i<n ; i++){
            XorElement = XorElement^nums[i];
        }
        return XorElement;


        // Better Approach --> HashTable [array]  & [Unordered_map]
        // unordered_map<int, int> st;
        // for (int i = 0; i< n; i++){
        //     st[nums[i]]++;
        // }

        // // --------WRONG---------
        // // for (int i = 0; i<n; i++){
        // //     if (st[i] == 1) return i;
        // // }

        // for (auto it: st){
        //     if (it.second == 1){
        //         return it.first;
        //     }
        // }
        // return -1;


        //Naive approach
        // for (int i = 0; i < n; i++) {
        //     int selected = nums[i];
        //     int count = 0;
        //     for (int j = 0; j < n; j++) {
        //         if (selected == nums[j]) count++;
        //     }
        //     if (count == 1) return selected;
        // }
        // return -1;
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