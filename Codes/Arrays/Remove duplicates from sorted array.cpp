#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int indexSet = 0;
        set<int> takenSetDataStructure;
        for (auto it : takenSetDataStructure){
            nums[indexSet] = it;
            indexSet++;
        }
        return takenSetDataStructure.size();
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