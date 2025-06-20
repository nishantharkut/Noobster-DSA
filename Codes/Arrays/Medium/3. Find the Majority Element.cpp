

/*
Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {

    public:
    int majorityElement(vector<int>& nums){
        int n = nums.size();
        unordered_map<int,int> occurences;
        
        //store
        for (int i = 0; i<n; i++){
            occurences[nums[i]]++;
        } 

        int target = n/2;
        return occurences[target+1];
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