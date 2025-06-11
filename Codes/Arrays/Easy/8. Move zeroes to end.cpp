#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();

        //Optimal Approach? 
        // --> hash? -> X 
        // --> 2 pointers -> yes

        
        int j;
        for (int i = 0; i<n; i++){
            if (arr[i] == 0){
                j = i;
                break;
            }
            
        }
        
        for (int i = j+1; i<n;i++){
            if (arr[i] !=0){
                swap(arr[i], arr[j]);
                j++;
            }
        }

        //Better Space Complexity
        //-------------------------------------
        // vector<int> tempN;
        // for (int i = 0; i<n;i++){
        //     if (arr[i]!=0) tempN.push_back(arr[i]);
        // }

        // int nonZeroElements = tempN.size();

        // for (int i = 0; i<nonZeroElements;i++){
        //     arr[i] = tempN[i];
        // }

        // for (int i = nonZeroElements; i<n;i++){
        //     arr[i] = 0;
        // }



        // vector<int> tempN, tempZero;
        // for (int i = 0; i<n;i++){
        //     if (arr[i] == 0) {tempZero.push_back(arr[i]);}
        //     else {tempN.push_back(arr[i]);}
        // }

        // for (int i = 0; i<tempN.size();i++){
        //     arr[i] = tempN[i];
        // }

        // for (int j = 0; j<tempZero.size();j++){
        //     arr[tempN.size()+j] =tempZero[j];
        // }
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