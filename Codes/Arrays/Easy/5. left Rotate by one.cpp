#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    void rotateArrayByOne(vector<int> &arr, int k)
    {
        int n = arr.size();
        for (int j = 0; j < k; j++)
        {
            int temp = arr[0];
            for (int i = 0; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            arr[n - 1] = temp;
        }
    }
};

void printArray(const vector<int> &nums)
{
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    Solution obj;

    vector<vector<int>> testCases = {
        {10, 20, 30, 40, 50},
        {99, 100},
        {42},
        {7, 7, 7, 7},
        {-5, -10, -15, -20},
        {0, -1, 2, -3, 4},
        {5, 6, 7, 8, 1}};

    for (int i = 0; i < testCases.size(); ++i)
    {
        int k;
        cout << "Test Case " << i + 1 << " - Before: ";
        printArray(testCases[i]);
        cout << "Enter number of positions to shift left (k): ";
        cin >> k;
        k = k % testCases[i].size(); // Optional: handle large k
        obj.rotateArrayByOne(testCases[i], k);
        cout << "After: ";
        printArray(testCases[i]);
        cout << "-----------------------" << endl;
    }

    return 0;
}
