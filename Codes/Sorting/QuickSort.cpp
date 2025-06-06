#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
        int i = low;
        int j = high;

        while (i < j) {
            while (arr[i] <= pivot && i < high) i++;
            while (arr[j] > pivot && j > low) j--;
            if (i < j) swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]);
        return j;
    }

    void qsHelper(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivotIdx = partition(arr, low, high);
            qsHelper(arr, low, pivotIdx - 1);
            qsHelper(arr, pivotIdx + 1, high);
        }
    }

    vector<int> quickSort(vector<int>& arr) {
        qsHelper(arr, 0, arr.size() - 1);
        return arr;
    }
};

// Utility function to print array
void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

// Test cases
void runTestCases() {
    Solution ob;

    vector<vector<int>> testCases = {
        {},                          // Empty array
        {5},                         // Single element
        {2, 1},                      // Two elements
        {1, 2, 3, 4, 5},             // Already sorted
        {5, 4, 3, 2, 1},             // Reverse sorted
        {3, 1, 4, 1, 5, 9, 2, 6},    // Random
        {7, 7, 7, 7},                // All elements equal
        {INT_MAX, INT_MIN, 0},       // Edge values
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        cout << "Test Case #" << i + 1 << ": Original: ";
        printArray(testCases[i]);

        vector<int> result = ob.quickSort(testCases[i]);

        cout << "Sorted: ";
        printArray(result);
        cout << "-------------------------\n";
    }
}

// User input
void userInputMode() {
    int n;
    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Solution ob;
    vector<int> sorted = ob.quickSort(arr);

    cout << "Sorted Array: ";
    printArray(sorted);
}

int main() {
    cout << "Choose Mode:\n";
    cout << "1. Run Predefined Test Cases\n";
    cout << "2. Enter Your Own Array\n";
    cout << "Enter your choice (1/2): ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        runTestCases();
    } else if (choice == 2) {
        userInputMode();
    } else {
        cout << "Invalid choice. Exiting.\n";
    }

    return 0;
}
