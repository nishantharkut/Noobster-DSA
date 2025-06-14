#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        // DUTCH FLAG ALGORITHM
        int low = 0, mid = 0, high = n-1;

        while (mid<=high){
            if (nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1){
                mid++;
            }
            else { //nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }


        //better approach
        // int count0 = 0,count1 = 0, count2 = 0;
        // for (int i = 0; i<n; i++){
        //     if (nums[i] == 0) count0++;
        //     else if (nums[i] == 1) count1++;
        //     else count2++;
        // } 

        // for (int i =0; i<count0; i++) nums[i] = 0;
        // for (int i = count0; i<count0+count1; i++) nums[i] = 1;
        // for (int i = count0+count1; i<count0+count1+count2; i++) nums[i] = 2;

        // CLEARLY A WRONG ANSWER AS THE QUESTION REQUIRES A CONSTANT SPACE BUT IT IS USING MORE THAN THAT
        // vector<int> temp0, temp1, temp2;

        // for (int i = 0; i<n; i++){
        //     if (nums[i] == 0) temp0.push_back(0);
        //     else if (nums[i] == 1) temp1.push_back(1);
        //     else temp2.push_back(2);
        // }

        // vector<int> result;
        // nums.clear();
        // nums.insert(nums.end(), temp0.begin(), temp0.end());
        // nums.insert(nums.end(), temp1.begin(), temp1.end());
        // nums.insert(nums.end(), temp2.begin(), temp2.end());
        
    }
};

int main() {
    Solution ob;

    vector<vector<int>> testCases = {
        {0, 0, 0, 0},             // all 0s
        {1, 1, 1, 1},             // all 1s
        {2, 2, 2, 2},             // all 2s
        {0, 1, 2},                // already sorted
        {2, 1, 0},                // reverse sorted
        {2, 0, 2, 1, 1, 0},       // mixed case
        {1},                     // single 1
        {2},                     // single 2
        {0},                     // single 0
        {0, 2},                  // short mixed
        {2, 1},                  // short reverse
        {1, 0},                  // short reverse
        {0, 1, 1, 0, 2, 2, 0},   // complex mixed
        {1, 2, 0, 1, 2, 0, 1},   // another mixed
        {},                      // empty array
        {1, 1, 0, 0, 2, 2, 1, 0, 2}, // all elements mixed
        {0, 1, 0, 1, 0, 1},      // 0s and 1s only
        {1, 2, 1, 2, 1, 2},      // 1s and 2s only
        {0, 2, 0, 2, 0, 2},      // 0s and 2s only
    };

    for (size_t i = 0; i < testCases.size(); i++) {
        vector<int> nums = testCases[i];
        ob.sortColors(nums);

        cout << "Test Case " << i + 1 << ": ";
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
