#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> temp;
        int i = 0;
        int j = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                temp.push_back(nums1[i]);
                i++;
            }
            // else if (nums1[i] == nums2[j]){
            //     temp.push_back(nums2[j]);
            //     i++;
            //     j++;
            // }
            else
            {
                temp.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m)
        {
            temp.push_back(nums1[i]);
            i++;
        }

        while (j < n)
        {
            temp.push_back(nums2[j]);
            j++;
        }

        for (int i = 0; i < temp.size(); i++)
        {
            nums1[i] = temp[i];
        }

        // Takes O((n+m) log (n+m))
        // vector<int>temp1;
        // for (int i = 0; i<m;i++){
        //     temp1.push_back(nums1[i]);
        // }
        // for (int i = 0; i<n;i++){
        //     temp1.push_back(nums2[i]);
        // }

        // for (int i = 0; i<temp1.size();i++){
        //     nums1[i] = temp1[i];
        // }
        // sort(nums1.begin(), nums1.end());
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin >> N;
        Solution ob;
    }
    return 0;
}