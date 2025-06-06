#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {

    public:
    void ArrkaInput(vector<int>& arr){
        int n = arr.size();
        cout << "enter the array: ";
        for (int i = 0; i<n; i++){
            cin >> arr[i];
        }
        cout << endl;
    }

    // Divide
    void mergesort(vector<int>& arr, int low, int high){
        if (low<high){
            int mid = low + (high -low)/2;
            mergesort(arr, low, mid);
            mergesort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }
    }

    // Conquer - Merge
    void merge(vector<int>& arr, int low, int mid, int high){
        int leftptr = low;
        int rightptr = mid+1;
        int n = arr.size();
        //arr to store the merged array temporory
        vector<int> temp;
        int i = 0;
        while (leftptr<=mid && rightptr <= high){
            if (arr[leftptr]<arr[rightptr]){
                temp.emplace_back(arr[leftptr]);
                i++;
                leftptr++;
            }
            else{
                temp.emplace_back(arr[rightptr]);
                i++;
                rightptr++;
            }
        }
        
        // when left side gets completed
        // that is right side of array is remaining
        while (rightptr<= high){
            temp.emplace_back(arr[rightptr]);
                i++;
                rightptr++;
        }

        // when right side gets completed
        // that is left side of array is remaining
        while (leftptr<=mid){
            temp.emplace_back(arr[leftptr]);
                i++;
                leftptr++;
        }

        // make the temp arr == original arr
        // --------------MISTAKE DONE HERE-------------
        // for loop should be from low to high to copy the temp arr to original
        for (int i = low; i<= high; i++){
            arr[i] = temp[i-low];
        }
    }




  };

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        vector<int> arr(N);
        Solution ob;
        ob.ArrkaInput(arr);

        ob.mergesort(arr, 0, N - 1);

        cout << "Sorted array: ";
        for (auto i : arr){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}