// Given a binary array nums, return the maximum number of consecutive 1's in the array.
// Example 1:
// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

// Example 2:
// Input: nums = [1,0,1,1,0,1]
// Output: 2

// Constraints:
// 1 <= nums.length <= 10^5
// nums[i] is either 0 or 1.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxCount = 0;
        for (int start = 0; start < nums.size(); start++){
            if (nums[start] == 0){
                count = 0;
                
            }
            else{
                count++;
            }
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 1, 0, 1, 1, 1},         // Output: 3 (given example)
        {1, 0, 1, 1, 0, 1},         // Output: 2 (given example)
        {1, 1, 1, 1, 1, 1},         // Output: 6 (all 1s)
        {0, 0, 0, 0, 0, 0},         // Output: 0 (all 0s)
        {1, 0, 1, 0, 1, 0},         // Output: 1 (alternating)
        {1},                        // Output: 1 (single 1)
        {0},                        // Output: 0 (single 0)
        {1, 1, 1, 0, 1, 1, 1, 1},   // Output: 4 (two 1-chunks)
        {1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1}, // Output: 3
        {},                         // Output: 0 (empty input — edge case)
        // Large test case
        vector<int>(1e5, 1),        // Output: 100000 (all 1s, maximum size)
    };

    Solution ob;
    for (int i = 0; i < testCases.size(); i++) {
        int result = ob.findMaxConsecutiveOnes(testCases[i]);
        cout << "Test case " << i + 1 << " -> Output: " << result << endl;
    }

    return 0;
}